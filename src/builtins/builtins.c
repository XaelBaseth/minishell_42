/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:41:52 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/12 09:34:45 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Handles the builtins commands. */
bool	builtins(t_data *data)
{
	if (line_is(data, "env"))
		print_env(data);
	else if (line_starts_by(data, "echo "))
		do_echo(data);
	else if (line_is(data, "pwd"))
		get_pwd(data);
	else
		return (false);
	return (true);
}