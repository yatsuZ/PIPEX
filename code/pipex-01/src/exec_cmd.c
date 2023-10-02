/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:21:56 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/02 22:04:16 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/pipex.h"

void	exec_cmd1(t_cmd *cmd, char **env)
{
	pid_t	pid;

	pid = fork();
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

void	exec_f1_to_cmd1(t_pipex *p)
{
	p->cmd1->pid = fork();
	if (p->cmd1->pid < 0)
		perror("fork");
	if (!p->cmd1->pid)
	{
		p->f1->fd = open(p->f1->path, O_RDONLY);
		if (p->f1->fd < 0)
			erreur_dans_fork(p, 5);
		close(p->pipfd[0]);
		dup2(p->f1->fd, STDIN_FILENO);
		// dup2(p->pipfd[1], STDOUT_FILENO);
		close(p->f1->fd);
		// close(p->pipfd[1]);
		execve(p->cmd1->path, p->cmd1->cmd, p->env);
	}
}
