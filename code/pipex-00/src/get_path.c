/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:48:46 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/28 16:02:23 by yatsu            ###   ########.fr       */
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

// char	*local_path(char *cmd)
// {

// }

char	*get_path(char **env, char *cmd, int *error)
{
	char	*path;
	char	*all_path;
	char	**tab_path;
	size_t	i;

	all_path = find_path(env);
	if (!path)
	{
		
	}
	tab_path = ft_split(all_path, ':');
	i = 0;

}