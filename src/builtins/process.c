/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:08:31 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/22 10:05:47 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Create the processes where to execute the command inputed.
	t_args *input : command inputed.
	t_data *data : environment in which the command must be executed.
*/
void	create_processes(t_args *input, t_data *data)
{
	__pid_t	child_pid;
	int	stat_loc;
	child_pid = fork();
	if (child_pid < 0)
		panic("Fork failed.");
	if (child_pid == 0)
 		execute_cmd(input, data);
	else
		waitpid(child_pid, &stat_loc, WUNTRACED);
}