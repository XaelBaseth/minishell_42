/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:17:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/10 10:35:12 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


void	execute_in_path(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("command in exec is: %s\n", data->input);
	while (i < data->nb_path)
	{
		ft_printf("Data path: %s\n", data->arr_path[i].path);
		ft_printf("Returns of access: %d\n", access(data->arr_path[i].path,
			X_OK));
		if (access(data->arr_path[i].path, X_OK) == 0)
		{
			ft_printf("Looking for %s in %s.\n", data->input,
				data->arr_path[i].path);
			char *exec_args[] = {data->arr_path[i].path, data->input, NULL};
			execve(data->arr_path[3].path, exec_args, data->envp);
			panic(EXEC_ERR);
		}
		i++;
	}
	ft_printf("%s not found in any directories in PATH\n", data->input);
}
