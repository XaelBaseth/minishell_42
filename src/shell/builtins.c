/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:41:52 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/16 13:03:15 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shell.h"

extern int	g_signal;

/*
	Sets the value of the global int used for the signal.
	@param int `status`
	@returns `int` - the signal
*/
int	set_g_status(int status)
{
	g_signal = status;
	return (g_signal);
}

/*	
Handles the builtins commands that you cannot in the path.
	@param t_args `*input` : command inputed.
	@param t_data `*data` : environment in which the command must be executed.
	@returns `true` if the input is a builtins functions. 
 */
bool	builtins(t_args *input, t_data *data)
{
	if (!input->argv[0])
		return (true);
	if (ft_strcmp(input->argv[0], "env") == 0)
		print_env(data);
	else if (ft_strcmp(input->argv[0], "echo") == 0)
		do_echo(data);
	else if (ft_strcmp(input->argv[0], "pwd") == 0)
		get_pwd(data);
	else if (ft_strcmp(input->argv[0], "exit") == 0)
		do_exit(data);
	else if (ft_strcmp(input->argv[0], "cd") == 0)
		do_cd(data);
	else if (ft_strcmp(input->argv[0], "unset") == 0)
		do_unset(data);
	else if (ft_strcmp(input->argv[0], "export") == 0)
		do_export(data);
	else
		return (false);
	return (true);
}
