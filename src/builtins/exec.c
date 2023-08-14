/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:17:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/14 13:14:20 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Looks for command to be executed in PATH variables and execute 
	them. */
static void	execute_in_path(t_data *data)
{
	int	i;
	int	executed;

	i = -1;
	executed = 0;
	while (++i < data->nb_path)
	{
		if (access(data->arr_path[i].path, X_OK) == 0)
		{
			char *exec_args[] = {data->input, NULL};
			ft_printf("exec_args:");
			for (int j = 0; exec_args[j] != NULL; j++)
				ft_printf("  %d: %s\n", j, exec_args[j]);
			ft_printf("Trying to execute: %s\n", data->arr_path[i].path);
			int exec_result = execve(data->arr_path[i].path, exec_args, data->envp);
			if (exec_result == -1)
				perror("execve");
			else
				executed = 1;
		}
	}
	if (!executed)
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
