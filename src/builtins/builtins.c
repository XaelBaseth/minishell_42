/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:41:52 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/18 07:59:25 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Handles the builtins commands that you cannot in the path.
	t_args *input : command inputed.
	t_data *data : environment in which the command must be executed.
 */
bool	builtins(t_args *input, t_data *data)
{
	if (streq(input->argv[0], "env"))
		print_env(data);
	else if (streq(input->argv[0], "echo "))
		do_echo(data);
	else if (streq(input->argv[0], "pwd"))
		get_pwd(data);
	else
		return (false);
	return (true);
}