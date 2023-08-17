/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:16:52 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/17 09:43:44 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	change_pwd(t_data *data)
{
	(void)data;
}

void	update_old_pwd(t_data *data, char *old_pwd)
{
	ft_strlcpy(data->old_path, old_pwd, ft_strlen(old_pwd));
}

void	do_cd(t_data *data)
{
	(void)data;
	// char	temp[PATH_MAX];

	// getcwd(temp, PATH_MAX);
	// data->old_path = from;
	// if (data->args[1] == NULL || strncmp(data->args[1], "~", 1) == 0)
	// {
	// 	update_old_pwd(&temp[0], data);
	// 	chdir(getenv("HOME"));
	// 	change_pwd(data);
	// 	return ;
	// }
	// if (streq(data->args[1], "-"))
	// {
	// 	do_cd(data, data->old_path);
	// 	// cd to old pwd
	// 	return ;
	// }
	// if (chdir(data->args[1]) == SUCCESS)
	// {
	// 	update_old_pwd(&temp[0], data);
	// 	change_pwd(data);
	// }
}