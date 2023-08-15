/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:46:50 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/15 17:25:29 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	checks first the amount of arguments.
	
	- if there are multiple arguments and the first is correct, 
	the shell doesn't exit and shows "bash: exit: too many arguments"
	- if the first argument is incorrect, the shell exits and shows "bash: exit: truc: numeric argument required"

	- if there is only one argument, the shell exits.
		if the argument is incorrect, the shells shows "bash: exit: truc: numeric argument required"
*/
bool	do_exit(t_data *data)
{
	ft_printf("exit\n");
	if (data->argc > 2)
	{
		if (is_int(data->args[1]))
			ft_printf("minishell: exit: too many arguments\n");
		else
		{
			ft_printf("minishell: exit: %s: numeric argument required\n", data->args[1]);
			free_all(data);
			gc_free_all();
			exit(0);
		}
		return (true);
	}
	else
	{
		if (data->argc == 2 && !is_int(data->args[1]))
			ft_printf("minishell: exit: numeric argument required\n");
		free_all(data);
		gc_free_all();
		exit(0);
	}
	return (true);
}
