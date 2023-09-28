/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:21:56 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/29 01:29:49 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/pipex.h"

void	exec_cmd1(t_cmd *cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	ft_printf("PID == %d\n\n", pid);
	if (pid < 0)
		perror("fork");
	if (pid == 0)
	{
		// fd[0] = open(av[1], O_RDONLY);
		// if (fd[0] < 0)
		// 	terminate(av[1]);
		if (cmd->cmd[0] && cmd->path)
		{
			execve(cmd->path, cmd->cmd, env);
		}
		// else
		// 	cmd_error(cmd);
	}
}