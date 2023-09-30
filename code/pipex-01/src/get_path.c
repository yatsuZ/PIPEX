/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:48:46 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/30 04:11:24 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/pipex.h"

char	*find_path(char **env)
{
	size_t	i;

	i = 0;
	if (!env[0])
		return	(NULL);
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return	(env[i]+5);
		i++;
	}
	return (NULL);
	
}

char	*local_path(char *str, int *error)
{
	char	*path;

	if (ft_strncmp(str, "./", 2) && str[0] != '/')
		path = ft_strjoin("./", str);
	else
		path = ft_strdup(str);
	if (!path && str)
		return (*error = 1, NULL);
	if (!access(path, F_OK))
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
	return(free(tmp), tmp = NULL, res);
}

char	*get_path_cmd(char **env, char *cmd, int *error)
{
	char	*path;
	char	**tab_path;
	size_t	i;

	tab_path = ft_split(find_path(env), ':');
	if (!tab_path && find_path(env))
		return (*error = 1, NULL);
	i = 0;
	while (tab_path && tab_path[i])
	{
		path = triple_join(tab_path[i++], "/", cmd, error);
		if (*error)
			return (NULL);
		else if (!access(path, F_OK) && !access(path, X_OK) && !access(path, R_OK))
			return (free_tab(tab_path), path);
		else if (!access(path, F_OK))
			return(free_tab(tab_path), *error = 2, path);
		free(path);
	}
	path = local_path(cmd, error);
	if (!access(path, F_OK) && !access(path, X_OK) && !access(path, R_OK))
		return(free_tab(tab_path), path);
	else if (!access(path, F_OK))
		return(free_tab(tab_path), *error = 2, path);
	return (free_tab(tab_path), free(path), NULL);
}
