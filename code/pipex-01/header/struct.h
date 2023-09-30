/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:05:44 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/29 21:00:07 by yatsu            ###   ########.fr       */
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
	int		fd;
}	t_cmd;

typedef struct s_file
{
	char	*path;
	int		fd;
}	t_file;

typedef struct s_pipex
{
	t_cmd	*cmd1;
	t_file	*f1;
	char	**env;
	int		error;
	int		status;
}	t_pipex;

#endif