/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:48:46 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/29 00:55:16 by yatsu            ###   ########.fr       */
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

char	*local_path(char *cmd, int *error)
{
	char	*path;

	if (ft_strncmp(cmd, "./", 2) && cmd[0] != '/')
		path = ft_strjoin("./", cmd);
	else
		path = ft_strdup(cmd);
	if (!path && cmd)
		return (*error = 1, NULL);
	if (!access(path, F_OK))
		return (path);
	if (cmd != path)
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

char	*get_path(char **env, char *cmd, int *error)
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
		path = triple_join(tab_path[i], "/", cmd, error);
		if (*error)
			return (NULL);
		else if (!access(path, F_OK))
			return (free_tab(tab_path), path);
		free(path);
		i++;
	}
	path = local_path(cmd, error);
	return(free_tab(tab_path), path);
}