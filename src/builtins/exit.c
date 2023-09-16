/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:46:50 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/16 13:04:16 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtins.h"

/*
	Print out the message requiring a code numeric to properly
	exit the minishell.
	@param `*data`:  environmnent of minishell.
*/
void	exit_numeric(t_data *data)
{
	ft_printf("minishell: exit: %s\
: numeric argument required\n", data->args->argv[1]);
	gc_free_all();
	exit(set_g_status(2));
}

/*
	Quit the minishell while handling the arguments and exit code
	signal.
	@param `*data`: environmnent of minishell.
	@returns `g_status` - int of the exit code of the command.
*/
int	do_exit(t_data *data)
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
