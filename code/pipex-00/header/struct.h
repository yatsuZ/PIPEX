/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:05:44 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/29 00:29:12 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "./import.h"

// je definie mes structure ici.

typedef struct s_cmd
{
	char	*argv;
	char	**cmd;
	char	*path;
}	t_cmd;

#endif