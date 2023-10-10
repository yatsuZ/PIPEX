/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:21:56 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/10 03:57:24 by yatsu            ###   ########.fr       */
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
		p->f2->fd = open(p->f2->path, O_WRONLY | O_CREAT | O_TRUNC, CREAT_WRITE);
		if (p->f2->fd < 0)
			erreur_dans_fork(p, 5);
		close(p->pipfd[0]);
		dup2(p->f1->fd, STDIN_FILENO);
		dup2(p->f2->fd, STDOUT_FILENO);
		close(p->f1->fd);
		close(p->f2->fd);
		// close(p->pipfd[1]);
		execve(p->cmd1->path, p->cmd1->cmd, p->env);
	}
}
