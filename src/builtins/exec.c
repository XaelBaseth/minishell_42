/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:17:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/14 09:08:37 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Looks for command to be executed in PATH variables and execute 
	them. */
static void	execute_in_path(t_data *data)
{
	int	i;

	i = 0;
	print_path(data);
	while (i < data->nb_path)
	{
		if (!access(data->arr_path[i].path, F_OK))
		{
			ft_printf("Looking for %s in %s.\n", data->input,
				data->arr_path[i].path);
			char *exec_args[] = {data->arr_path[i].path, data->input, NULL};
			ft_printf("exec_args:\n");
			for (int j = 0; exec_args[j] != NULL; j++) {
				ft_printf("  %d: %s\n", j, exec_args[j]);
			}
			ft_printf("Return of execve: %d\n", execve(data->arr_path[i].path,
				exec_args, data->envp));
			execve(data->arr_path[i].path, exec_args, data->envp);
			perror("execve");
			panic(EXEC_ERR);
		}
		else
			i++;
	}
	ft_printf("%s not found in any directories in PATH\n", data->input);
}
/*	Check if the command inputed is either part of the added built-ins
	function or part of the PATH functions. */
void	execute_cmd(t_data *data)
{
	if (builtins(data))
		return ;
	else
	{
		execute_in_path(data);
		return ;
	}
}
