/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:37:22 by axel              #+#    #+#             */
/*   Updated: 2023/08/16 11:06:40 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
< Redirecting Input:
	The < symbol is used to redirect the input of a command from a file.
> Redirecting Output:
	The > symbol is used to redirect the output of a command to a file, 
	overwriting the file if it already exists.
<< Here Document:
	The << symbol followed by a delimiter allows you to input multiple 
	lines until a line containing the delimiter is seen.
>> Redirecting Output in Append Mode:
	The >> symbol is used to redirect output to a file in append mode, 
	meaning it adds the output to the end of the file without overwriting
	existing content.
*/

void	redirect_input(t_args *input)
{
	char	*buffer;
	int		fd[2];

	input->operator = REDIR_INPUT;
	pipe(fd);
	while (1)
	{
		buffer = readline("< ");
		if (ft_strncmp(buffer, input->argv[0], 2))
			break ;
		ft_putendl_fd(buffer, fd[1]);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	free(buffer);
}


void	exec_redirect(t_args *input, t_data *data)
{
	if (input->operator == REDIR_INPUT)
		redirect_input(input);
	if (input->operator == NONE)
		execute_cmd(input, data);
}