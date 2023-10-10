/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:21:56 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/10 18:18:44 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/pipex.h"

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
		dup2(p->pipfd[1], STDOUT_FILENO);
		close(p->f1->fd);
		close(p->pipfd[1]);
		execve(p->cmd1->path, p->cmd1->cmd, p->env);
	}
}

int	my_open(char *path)
{
	return (open(path, O_WRONLY | O_CREAT | O_TRUNC, CREAT_WRITE));
}

void	exec_cmd2_to_f2(t_pipex *p)
{
	p->cmd2->pid = fork();
	if (p->cmd2->pid < 0)
		perror("fork");
	if (!p->cmd2->pid)
	{
		p->f2->fd = my_open(p->f2->path);
		if (p->f2->fd < 0)
			erreur_dans_fork(p, 8);
		close(p->pipfd[1]);
		dup2(p->pipfd[0], STDIN_FILENO);
		dup2(p->f2->fd, STDOUT_FILENO);
		close(p->pipfd[0]);
		close(p->f2->fd);
		execve(p->cmd2->path, p->cmd2->cmd, p->env);
	}
}

void	exec(t_pipex *p)
{
	exec_f1_to_cmd1(p);
	exec_cmd2_to_f2(p);
	close(p->pipfd[0]);
	close(p->pipfd[1]);
	waitpid(-1, &(p->status), 0);
	waitpid(-1, &(p->status), 0);
}
