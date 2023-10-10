/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:48:46 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/10 03:05:07 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/pipex.h"

char	*find_path(char **env)
{
	size_t	i;

	i = 0;
	if (!env[0])
		return (NULL);
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*local_path(char *str, int *error, int param)
{
	char	*path;

	if (ft_strncmp(str, "./", 2) && str[0] != '/')
		path = ft_strjoin("./", str);
	else
		path = ft_strdup(str);
	if (!path && str)
		return (*error = 1, NULL);
	if (!access(path, F_OK) || param)
		return (path);
	if (str != path)
		free(path);
	return (path = NULL, NULL);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

char	*triple_join(char *s1, char *s2, char *s3, int *error)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(s1, s2);
	if (s1 && s2 && !tmp)
		return (*error = 1, NULL);
	res = ft_strjoin(tmp, s3);
	if (tmp && s3 && !res)
		*error = 1;
	return (free(tmp), tmp = NULL, res);
}

char	*get_path_cmd(char **env, char *cmd, int *error)
{
	char	*p;
	char	**tab_path;
	size_t	i;

	tab_path = ft_split(find_path(env), ':');
	if (!tab_path && find_path(env))
		return (*error = 1, NULL);
	i = 0;
	while (tab_path && tab_path[i])
	{
		p = triple_join(tab_path[i++], "/", cmd, error);
		if (*error)
			return (NULL);
		else if (!access(p, F_OK) && !access(p, X_OK) && !access(p, R_OK))
			return (free_tab(tab_path), p);
		else if (!access(p, F_OK))
			return (free_tab(tab_path), *error = 2, p);
		free(p);
	}
	p = local_path(cmd, error, 0);
	if (!p)
		return (*error = 3, free_tab(tab_path), NULL);
	else if (!access(p, F_OK) && !access(p, X_OK) && !access(p, R_OK))
		return (free_tab(tab_path), p);
	return (free_tab(tab_path), *error = 2, p);
}
