/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:40:28 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/29 00:48:43 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/pipex.h"

t_cmd	*ft_init_cmd(char *argv, char **env, int *error)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (cmd == NULL)
		return (*error = 1, NULL);
	cmd->argv = argv;
	cmd->cmd = ft_split(cmd->argv, ' ');
	if (cmd && !cmd->cmd)
		return (cmd->path = NULL, *error = 1, cmd);
	cmd->path = get_path(env, cmd->cmd[0], error);
	return (cmd);
}

void	free_cmd(t_cmd *cmd)
{
	free(cmd->path);
	cmd->argv = NULL;
	free_tab(cmd->cmd);
	cmd->path = NULL;
	free(cmd);
	cmd = NULL;
}
