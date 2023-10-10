/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:42:17 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/10 18:22:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/pipex.h"

int	error_gestion(t_pipex *p)
{
	int	error;

	if (!p)
		return (ft_printf("ERROR\nGestion d'erreur la struct pipex NULL\n"), 1);
	error = p->error;
	if (error == 2)
		ft_printf("ERROR\nPas le droit d'execution ou de lecture ou de Read!\n\
		Soit il s'agit des fichier ou des commande\n");
	else if (error == 1)
		ft_printf("ERROR\nIl y a eu une erreur de Memoire, malloc -_-!\n\n");
	else if (error == 3)
		ft_printf("ERROR\nLa commande 1 OU 2 ne fue pas trouver.\n\n");
	else if (error == 4)
		ft_printf("ERROR\nle fichier 1 ne fue pas trouver.\n\n");
	else if (error == 6)
		ft_printf("ERROR\nGeneration de fd fail.\n\n");
	else if (error == 7)
		ft_printf("ERROR Write.\nOn ne peut pas ecrire dans \"%s\".\n", \
		p->f2->path);
	free_pipex(p);
	return (0);
}

void	erreur_dans_fork(t_pipex *p, int error)
{
	if (error == 5)
		ft_printf("Erreur dans le fichier IN fonction open fail.\n");
	else if (error == 8)
		ft_printf("Erreur dans le fichier OUT fonction open fail.\n");
	free_pipex(p);
	exit(0);
}
