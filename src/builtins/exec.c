/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:17:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/09 10:41:55 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	execute_in_path(t_data *data)
{
	//While PATH exist
	//if access the input via the path, with en exec mode OK is == 0
	//execve with data->path, data->input, data->envp from copy
	//returns an error if it returns
	//else printf an error message.
	ft_printf("command in exec is: %s\n", data->input);
	while (data->arr_path[3].path)
	{
		ft_printf("Data path: %s\n", data->arr_path[3].path);
		ft_printf("Returns of access: %d\n", access(data->arr_path[3].path, X_OK));
		if (access(data->arr_path[3].path, X_OK) == 0)
		{
			ft_printf("Looking for %s in %s.\n", data->input, data->path);
			execve(data->arr_path[3].path, &data->input, data->envp);
			return ;
		}
		else
		{
			perror("Error");
			panic(EXEC_ERR);
		}
	}
	ft_printf("%s not found in any directories in PATH\n", data->input);
}
