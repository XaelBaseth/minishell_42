/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:41:52 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/04 14:11:20 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
extern int	g_signal;

int		set_g_status(int status)
{
	g_signal = status;
	return (0);
}

/*	Handles the builtins commands that you cannot in the path.
	t_args *input : command inputed.
	t_data *data : environment in which the command must be executed.
 */
bool	builtins(t_args *input, t_data *data)
{
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
