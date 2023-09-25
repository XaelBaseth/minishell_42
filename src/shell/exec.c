/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:17:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/19 09:05:22 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shell.h"

extern int	g_signal;

/*	
	Looks for command to be executed in PATH variables and execute 
	them. 
	@param `*input` : command inputed.
	@param `*data` : environment in which the command must be executed.
*/
static void	execute_in_path(t_args *input, t_data *data)
{
	int		i;
	char	*bin_path;
	char	*temp;

	i = -1;
	while (++i < data->nb_path)
	{
		temp = ft_strjoin(data->arr_path[i].path, "/");
		bin_path = ft_strjoin(temp, input->argv[0]);
		if (!bin_path)
			ft_printf("%s not found in any directories in PATH\n",
				data->args->argv[0]);
		if (access(bin_path, F_OK | X_OK) == 0)
		{
			execve(bin_path, input->argv, data->envp);
			perror("execve");
			panic(EXEC_ERR);
		}
	}
	ft_printf("minishell: command not found: %s.\n", input->argv[0]);
	g_signal = 127;
}

/*	
	Check if the command inputed is either part of the added built-ins
	function or part of the PATH functions.
	@param `*input` : command inputed.
	@param `*data` : environment in which the command must be executed.
*/
void	exec_executable(t_args *input, t_data *data)
{
	if (builtins(input, data))
		return ;
	if (check_if_binary(data, input->argv[0]))
		return (exit(0));
	execute_in_path(input, data);
	exit(g_signal);
}

/*	
	Redirect towards the correct executor.
	@param `*input` : command inputed.
	@param `*data` : environment in which the command must be executed.
*/
void	execute_cmd(t_args *input, t_data *data)
{
	signal(SIGINT, sigint_handler);
	if (input->operator == PIPE)
		exec_pipe(input, data);
	else if (input->operator != NONE && input->operator != PIPE)
		exec_redirect(input, data);
	else
		exec_executable(input, data);
	exit(g_signal);
}
