/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:37:22 by axel              #+#    #+#             */
/*   Updated: 2023/08/22 10:08:37 by axel             ###   ########.fr       */
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
static void	redirect_heredoc(t_args *input)
{
	char	*buffer;
	int		fd[2];

	pipe(fd);
	while (1)
	{
		buffer = readline("> ");
		if (streq(buffer, input->argv[0]))
			break ;
		ft_putendl_fd(buffer, fd[1]);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	free(buffer);
}

static void	redirect_input(t_args *input)
{
	int		in_file;
	char	*error_msg;

	if (input->next->argv[0])
	{
		while (input->next->operator == REDIR_INPUT)
			input = input->next;
		if (access(input->next->argv[0], F_OK) == 0)
		{
			in_file = open(input->next->argv[0], O_RDONLY, 0666);
			dup2(in_file, STDIN_FILENO);
		}
		else
		{
			error_msg = ft_strjoin("minishell: ", input->next->argv[0]);
			perror(error_msg);
			gc_free_all();
			exit(EXIT_FAILURE);
		}
	}
}

static void	redirect_output(t_args *input)
{
	close(STDOUT_FILENO);
	while (input->next->operator == REDIR_OUTPUT_REPLACE
		|| input->next->operator == REDIR_OUTPUT_APPEND)
	{
		if (input->operator == REDIR_OUTPUT_REPLACE)
			open(input->next->argv[0], O_WRONLY | O_TRUNC | O_CREAT, 0666);
		else if (input->operator == REDIR_OUTPUT_APPEND)
			open(input->next->argv[0], O_WRONLY | O_APPEND | O_CREAT, 0666);
		input = input->next;
		close(1);		
	}
	if (input->operator == REDIR_OUTPUT_REPLACE)
			open(input->next->argv[0], O_WRONLY | O_TRUNC | O_CREAT, 0666);
		else if (input->operator == REDIR_OUTPUT_APPEND)
			open(input->next->argv[0], O_WRONLY | O_APPEND | O_CREAT, 0666);
}
/*	Check for the redirection symbol, or pipe, and execute the correct command.
	t_args *input: command inputed with the operator.
*/
void	exec_redirect(t_args *input)
{
	if (input->operator == REDIR_INPUT)
		redirect_input(input);
	else if (input->operator == REDIR_INPUT_UNTIL)
		redirect_heredoc(input);
	else
		redirect_output(input);
}