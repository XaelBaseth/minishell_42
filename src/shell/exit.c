/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:46:50 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/06 09:50:45 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exit_numeric(t_data *data)
{
	ft_printf("minishell: exit: %s\
: numeric argument required\n", data->args->argv[1]);
	gc_free_all();
	exit(set_g_status(2));
}

/*
	Checks first the amount of arguments.
	
	- if there are multiple arguments and the first is correct, 
	the shell doesn't exit and shows "bash: exit: too many arguments"
	- if the first argument is incorrect, the shell exits and shows
		"bash: exit: truc: numeric argument required"

	- if there is only one argument, the shell exits.
		if the argument is incorrect, the shells shows
			"bash: exit: truc: numeric argument required"
*/
int		do_exit(t_data *data)
{
	int	exit_status;
	
	ft_printf("exit\n");
	if (data->args->argc > 2)
	{
		if (is_int(data->args->argv[1]))
			ft_printf("minishell: exit: too many arguments\n");
		else
			exit_numeric(data);
		return (set_g_status(127));
	}
	else
	{
		if (data->args->argc == 2 && !is_int(data->args->argv[1]))
			exit_numeric(data);
		else if (data->args->argc == 2 && is_int(data->args->argv[1]))
			exit_status = ft_atoi(data->args->argv[1]);
		if (data->args->argc == 1)
			exit(set_g_status(0));
		else
			exit(set_g_status(exit_status));
		gc_free_all();
	}
	return (set_g_status(SUCCESS));
}
