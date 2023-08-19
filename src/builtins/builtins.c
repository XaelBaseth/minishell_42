/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:41:52 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/19 14:41:31 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Handles the builtins commands. */
bool	builtins(t_data *data)
{
	if (ft_strncmp(data->args[0], "env", 3) == 0)
		print_env(data);
	else if (ft_strncmp(data->args[0], "echo", 4) == 0)
		do_echo(data);
	else if (ft_strncmp(data->args[0], "pwd", 3) == 0)
		get_pwd(data);
	else if (ft_strncmp(data->args[0], "exit", 4) == 0)
		return (do_exit(data));
	else if (ft_strncmp(data->args[0], "cd", 2) == 0)
		do_cd(data);
	else if (ft_strncmp(data->args[0], "unset", 5) == 0)
		do_unset(data);
	else if (ft_strncmp(data->args[0], "export", 6) == 0)
		do_export(data);
	else
		return (false);
	return (true);
}



// bool	builtins(t_data *data)
// {
// 	if (line_is(data, "env"))
// 		print_env(data);
// 	else if (line_starts_by(data, "echo "))
// 		do_echo(data);
// 	else if (line_is(data, "pwd"))
// 		get_pwd(data);
// 	else if (line_starts_by(data, "exit"))
// 		return (do_exit(data));
// 	else
// 		return (false);
// 	return (true);
// }
