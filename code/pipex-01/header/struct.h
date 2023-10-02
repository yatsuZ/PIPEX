/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:05:44 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/02 21:32:40 by yassine          ###   ########.fr       */
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
	pid_t	pid;
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
	int		pipfd[2];
}	t_pipex;

#endif