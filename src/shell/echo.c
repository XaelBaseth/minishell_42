/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:54:55 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/23 15:25:36 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	is_parameter(char *str)
{
	int	i;

	i = 2;
	if (str[0] == '-' && str[1] == 'n')
	{
		while (str[i])
		{
			if (str[i] != 'n')
				return (false);
		}
		return (true);
	}
	return (false);
}

void	do_echo(t_data *data)
{
	int		i;
	bool	has_parameter;

	i = 1;
	has_parameter = false;
	while (data->args[i + 1] && is_parameter(data->args[i]))
		i++;
	if (i > 1)
		has_parameter = true;
	while (data->args[i + 1])
		ft_printf("%s ", data->args[i++]);
	ft_printf("%s", data->args[i]);
	if (!has_parameter)
		ft_printf("\n");
}
