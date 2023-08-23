/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:58:31 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/23 15:21:13 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	get_pwd(t_data *data)
{
	if (data->args[1])
	{
		ft_printf("pwd: too many arguments\n");
		return ;
	}
	ft_printf("%s\n", get_env(data, "PWD"));
}
