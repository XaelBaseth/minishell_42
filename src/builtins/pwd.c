/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:58:31 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/16 13:04:27 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtins.h"

/*
	Returns a string containing the path to the current working directory.
	@param `*data`: environment of minishell.
	@returns `g_status` - int of the exit code of the command.
*/
int	get_pwd(t_data *data)
{
	if (data->args->argv[1])
	{
		ft_printf("pwd: too many arguments\n");
		return (set_g_status(1));
	}
	ft_printf("%s\n", get_env(data, "PWD"));
	return (set_g_status(0));
}
