/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:08:31 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/16 13:03:41 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shell.h"

extern int	g_signal;

/*	
	Returns the number of arguments separated by operator in the input.
	@param `*input` : command inputed.
	@returns `size` - size total of the arguments separated by an operator.
*/
static int	lstsize(t_args *input)
{
	t_args	*temp;
	int		size;

	temp = input;
	size = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		size += 1;
	}
	return (size);
}

/*	
	Create the child processes where to execute the command inputed.
	@param `*input` : command inputed.
	@param `*data` : environment in which the command must be executed.
*/
void	create_processes(t_args *input, t_data *data)
{
	int	temp_status;

	if (lstsize(input) == 1)
	{
		if (!builtins(input, data) && fork() == 0)
		{
			signal(SIGINT, sigint_handler);
			exec_executable(input, data);
		}
	}
	else if (fork() == 0)
		execute_cmd(input, data);
	waitpid(-1, &temp_status, 0);
	if (!WTERMSIG(temp_status))
		g_signal = temp_status >> 8;
}
