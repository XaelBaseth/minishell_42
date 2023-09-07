/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:54:55 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/07 17:06:41 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static bool	is_parameter(char *str)
{
	int	i;

	i = 2;
	if (!str)
		return (false);
	if (str[0] == '-' && str[1] == 'n')
	{
		while (str[i])
		{
			if (str[i++] != 'n')
				return (false);
		}
		return (true);
	}
	return (false);
}

int	do_echo(t_data *data)
{
	int		i;
	bool	has_parameter;

	i = 1;
	has_parameter = false;
	while (i < data->args->argc && is_parameter(data->args->argv[i]))
		i++;
	if (i > 1)
		has_parameter = true;
	while (data->args->argv[i]
		&& data->args->argv[i + 1] && i < data->args->argc)
		ft_printf("%s ", data->args->argv[i++]);
	ft_printf("%s", data->args->argv[i]);
	if (!has_parameter)
		ft_printf("\n");
	return (set_g_status(SUCCESS));
}
