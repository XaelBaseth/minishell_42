/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:46:50 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/05 11:04:31 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	checks first the amount of arguments.
	
	- if there are multiple arguments and the first is correct, 
	the shell doesn't exit and shows "bash: exit: too many arguments"
	- if the first argument is incorrect, the shell exits and shows
		"bash: exit: truc: numeric argument required"

	- if there is only one argument, the shell exits.
		if the argument is incorrect, the shells shows
			"bash: exit: truc: numeric argument required"
*/
bool	do_exit(t_data *data)
{
	ft_printf("exit\n");
	if (data->args->argc > 2)
	{
		if (is_int(data->args->argv[1]))
			ft_printf("minishell: exit: too many arguments\n");
		else
		{
			ft_printf("minishell: exit: %s\
: numeric argument required\n", data->args->argv[1]);
			gc_free_all();
			exit(0);
		}
		return (true);
	}
	else
	{
		if (data->args->argc == 2 && !is_int(data->args->argv[1]))
			ft_printf("minishell: exit: numeric argument required\n");
		gc_free_all();
		exit(0);
	}
	return (true);
}
