/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:59:46 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/30 23:37:23 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/pipex.h"

// int	main(int ac, char **av, char **env)
// {
// 	t_cmd	*cmd1;
// 	int		error;
// 	char	*res;
// 	int		status;

// 	error = 0;
// 	if (ac < 3 || !av[1] || !av[2])
// 		return (ft_printf("ERREUR dans les parametres!!!\n\n"), 0);
// 	cmd1 = ft_init_cmd(av[1], env, &error);
// 	if (error == 1 && !cmd1)
// 		return (ft_printf("Il y a eu une erreur de Memoire!\n\n"), 1);
// 	else if (!cmd1->path)
// 		return (ft_printf("Aucune commande fue trouver,\nVoici le param : \"%s\"\n\n", cmd1->argv),free_cmd(cmd1), 0);
// 	ft_printf("Voici le chemin de la commande : \"%s\"\n", cmd1->argv);
// 	ft_printf("%s\n", cmd1->path);
// 	ft_printf("Execution de la cmd = \n");
// 	exec_cmd1(cmd1, env);
// 	waitpid(-1, &status, 0);
// 	free_cmd(cmd1);
// 	return (0);
// }

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	if (ac < 3 || !av[1] || !av[2])
		return (ft_printf("ERREUR dans les parametres!!!\n\n"), 0);
	pipex = ft_init_pipex(av, env);
	if (!pipex || pipex->error)
		return (error_gestion(pipex));
	// ft_printf("Voici le chemin de la commande : \"%s\"\n", pipex->cmd1->argv);
	// ft_printf("%s\n", pipex->cmd1->path);
	// ft_printf("Execution de la cmd = \n");
	// exec_cmd1(pipex->cmd1, env);
	// waitpid(-1, &(pipex->status), 0);
	free_pipex(pipex);
	return (0);
}

// faire gestion derreur avec pour chaque erreur soit pas trouver etc et cree les fonction dinitialisation.
