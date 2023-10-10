/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:53:57 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/10 18:23:48 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/pipex.h"

void	free_file(t_file *f)
{
	if (!f)
		return ;
	free(f->path);
	f->path = NULL;
	f->fd = 0;
	free(f);
}

t_file	*ft_init_file(char *path, int *error, int param)
{
	t_file	*file;

	if (*error)
		return (NULL);
	file = ft_calloc(1, sizeof(t_file));
	if (!file)
		return (*error = 1, NULL);
	file->path = local_path(path, error, param);
	file->fd = 0;
	if (param && \
	((access(file->path, F_OK)) || \
	(!access(file->path, F_OK) && (!access(path, W_OK)))))
		return (file);
	else if (param)
		return (*error = 7, file);
	if (!file->path)
		return (*error = 4, file);
	if (!access(file->path, F_OK) && !access(path, R_OK))
		return (file);
	return (*error = 2, file);
}

t_pipex	*ft_init_pipex(char **argv, char **env)
{
	t_pipex	*pipex;

	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->env = env;
	pipex->error = 0;
	if (pipe(pipex->pipfd) < 0)
		return (pipex->error = 6, pipex);
	pipex->f1 = ft_init_file(argv[1], &(pipex->error), 0);
	pipex->cmd1 = ft_init_cmd(argv[2], pipex->env, &(pipex->error));
	pipex->cmd2 = ft_init_cmd(argv[3], pipex->env, &(pipex->error));
	pipex->f2 = ft_init_file(argv[4], &(pipex->error), 1);
	return (pipex);
}

void	free_pipex(t_pipex *p)
{
	if (!p)
		return ;
	p->env = 0;
	p->error = 0;
	close(p->pipfd[0]);
	close(p->pipfd[1]);
	free_file(p->f1);
	free_file(p->f2);
	free_cmd(p->cmd1);
	free_cmd(p->cmd2);
	free(p);
	p = NULL;
}
