/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:59:46 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/10 03:01:24 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	if (ac < 4 || !av[1] || !av[2] || !av[3])
		return (ft_printf("ERREUR dans les parametres!!!\n\n"), 0);
	pipex = ft_init_pipex(av, env);
	if (!pipex || pipex->error)
		return (error_gestion(pipex));
	ft_printf("Voici le chemin de l\'argument : \"%s\"\n", pipex->cmd1->argv);
	ft_printf("%s\n", pipex->cmd1->path);
	ft_printf("Execution de la cmd = \n");
	exec_f1_to_cmd1(pipex);
	waitpid(-1, &(pipex->status), 0);
	return (free_pipex(pipex), 0);
}
