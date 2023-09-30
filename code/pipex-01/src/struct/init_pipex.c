/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:53:57 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/30 03:47:19 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/pipex.h"

t_cmd	*ft_init_pipex(int argc, char **argv, char **env)
{
	t_pipex	*pipex;

	if (argc < 3 || !argv[1] || !argv[2])
		return (ft_printf("ERREUR dans les parametres!!!\n\n"), NULL);
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		return (ft_printf("Il y a eu une erreur de Memoire!\n\n"), NULL);
	pipex->env = env;
	pipex->error = 0;
	pipex->cmd1 = ft_init_cmd(argv[2], pipex->env, &(pipex->error));
}

void	free_pipex(t_pipex *p)
{
	pipex->
}
