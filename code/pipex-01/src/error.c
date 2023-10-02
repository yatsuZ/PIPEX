/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:42:17 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/02 21:45:17 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/pipex.h"

int	error_gestion(t_pipex *p)
{
	int	error;

	if (!p)
		return (ft_printf("Gestion d'erreur la struct pipex NULL error\n"), 1);
	error = p->error;
	if (error == 2)
		ft_printf("Pas le droit d'execution ou de lecture ou de Read!\n\
		Soit il s'agit des fichier ou des commande\n");
	else if (error == 1)
		ft_printf("Il y a eu une erreur de Memoire, malloc -_-!\n\n");
	else if (error == 3)
		ft_printf("la commande 1 ne fue pas trouver.\n\n");
	else if (error == 4)
		ft_printf("le fichier 1 ne fue pas trouver.\n\n");
	else if (error == 6)
		ft_printf("Erreur generation de fd.\n\n");
	free_pipex(p);
	return (0);
}

void	erreur_dans_fork(t_pipex *p, int error)
{
	if (error == 5)
		ft_printf("Erreur dans le open fd ARRET du programme.\n\n");
	free(p);
	exit(0);
}