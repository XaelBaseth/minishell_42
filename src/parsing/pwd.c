/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:58:31 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/16 11:34:47 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	set_pwd(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], "PWD=", 4))
			data->pwd = ft_substr(data->envp[i],
					4, ft_strlen(data->envp[i]) - 4);
		i++;
	}
}

void	get_pwd(t_data *data)
{
	if (data->args[1])
	{
		ft_printf("pwd: too many arguments\n");
		return ;
	}
	ft_printf("%s\n", data->pwd);
}
