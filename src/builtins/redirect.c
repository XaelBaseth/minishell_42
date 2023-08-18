/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:37:22 by axel              #+#    #+#             */
/*   Updated: 2023/08/18 09:41:46 by acharlot         ###   ########.fr       */
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
 /*	Redirect the input of the command into a file.
	t_args *input: command that has been inputed.
 */
void	redirect_input(t_args *input)
{
	char	*buffer;
	int		fd[2];

	pipe(fd);
	while (1)
	{
		buffer = readline("< ");
		if (streq(buffer, input->argv[0]))
			break ;
		ft_putendl_fd(buffer, fd[1]);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	free(buffer);
}
/*	Check for the redirection symbol, or pipe, and execute the correct command.
	t_args *input: command inputed with the operator.
*/
void	exec_redirect(t_args *input)
{
	if (input->operator == REDIR_INPUT)
		redirect_input(input);
}