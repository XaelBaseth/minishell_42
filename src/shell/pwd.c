/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:58:31 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/04 14:28:46 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int		get_pwd(t_data *data)
{
	if (data->args->argv[1])
	{
		ft_printf("pwd: too many arguments\n");
		return (set_g_status(1));
	}
	ft_printf("%s\n", get_env(data, "PWD"));
	return (set_g_status(0));
}
