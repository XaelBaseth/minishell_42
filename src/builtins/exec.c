/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:17:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/04 11:15:02 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Looks for command to be executed in PATH variables and execute 
	them. 
	t_args *input : command inputed.
	t_data *data : environment in which the command must be executed.
*/
static void	execute_in_path(t_args *input, t_data *data)
{
	int	i;
	char *bin_path;
	char *temp;

	i = -1;
	while (++i < data->nb_path)
	{
		temp = ft_strjoin(data->arr_path[i].path, "/");
		bin_path = ft_strjoin(temp, input->argv[0]);
		if (access(bin_path, F_OK | X_OK) == 0)
		{
			execve(bin_path, input->argv, data->envp);
			perror("execve");
			panic(EXEC_ERR);
		}
	}
	ft_printf("%s not found in any directories in PATH\n", data->args->argv[0]);
}

/*	Check if the command inputed is either part of the added built-ins
	function or part of the PATH functions.
	t_args *input : command inputed.
	t_data *data : environment in which the command must be executed.
*/
void	exec_executable(t_args *input, t_data *data)
{
	if (builtins(input, data))
		return ;
	execute_in_path(input, data);
}

/*	Redirect towards the correct executor.
	t_args *input : command inputed.
	t_data *data : environment in which the command must be executed.
*/
void	execute_cmd(t_args *input, t_data *data)
{
	if (input->operator == PIPE)
		exec_pipe(input, data);
	else if (input->operator == NONE)
		exec_executable(input, data);
	else
		exec_redirect(input, data);
	exit(EXIT_SUCCESS);
}
