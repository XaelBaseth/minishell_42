/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:17:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/16 11:07:27 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Looks for command to be executed in PATH variables and execute 
	them. */
static void	execute_in_path(t_data *data)
{
	int	i;
	char *bin_path;
	char *temp;
	char **input;

	data->args->operator = NONE;
	i = -1;
	input = data->args->argv;
	while (++i < data->nb_path)
	{
		temp = ft_strjoin(data->arr_path[i].path, "/");
		bin_path = ft_strjoin(temp, data->input);
		if (access(bin_path, F_OK | X_OK) == 0)
		{
			execve(bin_path, input, data->envp);
			perror("execve");
			panic(EXEC_ERR);
		}
	}
	ft_printf("%s not found in any directories in PATH\n", data->input);
}


/*	Check if the command inputed is either part of the added built-ins
	function or part of the PATH functions. */
void	execute_cmd(t_args *input, t_data *data)
{
	if (input->operator == NONE)
	{
		if (builtins(data))
			return ;
		execute_in_path(data);
		return ;
	}
	else
	ft_printf("OK");
		exec_redirect(input, data);
}
