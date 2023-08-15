/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:08:31 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/15 15:28:48 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Create the child-processes where to execute the command. */
// void	create_processes(t_data *data)
// {
// 	__pid_t	child_pid;
// 	int	stat_loc;

// 	child_pid = fork();
// 	if (child_pid < 0)
// 		panic("Fork failed.");
// 	if (child_pid == 0)
//  		execute_cmd(data);
// 	else
// 		waitpid(child_pid, &stat_loc, WUNTRACED);
// }
void	create_processes(t_data *data)
{
	int	stat_loc;

	if (!builtins(data) && fork() == 0)
	{
 		execute_cmd(data);
	}
	// if (child_pid < 0)
	// 	panic("Fork failed.");
	// if (child_pid == 0)
	// {
 	// 	execute_cmd(data);
	// }
	// else
	waitpid(-1, &stat_loc, WUNTRACED);
}