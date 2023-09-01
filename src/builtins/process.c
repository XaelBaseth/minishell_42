/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:08:31 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/01 11:09:44 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Returns the number of arguments in the input.
	t_args *input: command inputed.
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


/*	Create the processes where to execute the command inputed.
	t_args *input : command inputed.
	t_data *data : environment in which the command must be executed.
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
}

