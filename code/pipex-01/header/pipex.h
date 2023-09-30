/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:02:50 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/30 23:33:28 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./struct.h"

// La ou j'apelle mes fonction

// Init structure

t_cmd	*ft_init_cmd(char *argv, char **env, int *error);
t_pipex	*ft_init_pipex(char **argv, char **env);
void	free_cmd(t_cmd *cmd);
void	free_tab(char **tab);
char	*get_path_cmd(char **env, char *cmd, int *error);
void	free_pipex(t_pipex *pipex);
int		error_gestion(t_pipex *p);

// PIP

char	*local_path(char *cmd, int *error);
void	exec_cmd1(t_cmd *cmd, char **env);

#endif