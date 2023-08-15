/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:46:50 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/15 14:19:51 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	do_exit(t_data *data)
{
	ft_printf("exit\n");
	/*
		checks first the amount of arguments.
		
		- if there are multiple arguments and the first is correct, 
		the shell doesn't exit and shows "bash: exit: too many arguments"
		- if the first argument is incorrect, the shell exits and shows "bash: exit: truc: numeric argument required"

		- if there is only one argument, the shell exits.
			if the argument is incorrect, the shells shows "bash: exit: truc: numeric argument required"
	*/

	(void)data;
	return (false); // return false exits the program (see in `main`)
}