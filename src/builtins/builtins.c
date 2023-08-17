/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:41:52 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/17 13:27:42 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Handles the builtins commands. */
bool	builtins(t_args *input, t_data *data)
{
	printf("args passed to builtins: %s", input->argv[0]);
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