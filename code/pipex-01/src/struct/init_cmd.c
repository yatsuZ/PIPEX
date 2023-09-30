/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:40:28 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/01 00:01:32 by yassine          ###   ########.fr       */
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
	cmd->path = get_path_cmd(env, cmd->cmd[0], error);
	cmd->fd = 0;
	return (cmd);
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	cmd->argv = NULL;
	cmd->fd = 0;
	free(cmd->path);
	free_tab(cmd->cmd);
	free(cmd);
}
