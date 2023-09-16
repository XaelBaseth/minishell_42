/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:50:54 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/16 13:29:04 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

/*	LIBRARY	*/

# include "minishell.h"

/*	STRUCTURE	*/

typedef struct s_args	t_args;
typedef struct s_data	t_data;

/*	FUNCTIONS	*/

void		store_path(char *path, t_data *data);
void		print_path(t_data *data);
void		execute_cmd(t_args *input, t_data *data);
void		exec_executable(t_args *input, t_data *data);
void		create_processes(t_args *input, t_data *data);
void		exec_redirect(t_args *input, t_data *data);
void		exec_pipe(t_args *input, t_data *data);
void		exec_heredoc(t_args *input, t_data *data);
void		exec_multiple_heredoc(t_args *input, t_data *data);
char		*get_path(t_data *data);
bool		builtins(t_args *input, t_data *data);
bool		check_if_binary(t_data *data, char *arg);
int			set_g_status(int status);

#endif