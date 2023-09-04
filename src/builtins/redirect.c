/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:37:22 by axel              #+#    #+#             */
/*   Updated: 2023/09/04 14:37:47 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

 /*	Allows to input multiple line lines until a line containing the 
 	delimiter is seen via the '<<' input.
	t_args *input: command that has been inputed.
 */
static void	redirect_heredoc(t_args *input)
{
	char	*buffer;
	int		fd[2];

	pipe(fd);
	while (1 && !g_signal)
	{
		buffer = readline("\033[32m$> \033[0m");
		if (!buffer)
		{
			ft_putendl_fd("Error in heredoc.\n", fd[1]);
			exit(EXIT_FAILURE);
		}
		if (streq(buffer, input->next->argv[0]))
		{
			free(buffer);
			break ;
		}
		ft_putendl_fd(buffer, fd[1]);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	g_signal = 0;
}

/*	Redirect the input of a command into the file via the '<' operator.
	t_args *input: command that has been inputed.
*/
static void	redirect_input(t_args *input)
{
	int		in_file;

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
			panic("An error occured.");
	}
}

/*	Check the operator used and create or replace a document if '>', or
	append a document if '>>'.
	t_args *input: command that has been inputed.
*/
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
void	exec_redirect(t_args *input, t_data *data)
{
	t_args *temp;

	temp = input;
	if (input->operator == REDIR_INPUT)
		redirect_input(input);
	else if (input->operator == REDIR_INPUT_UNTIL)
		redirect_heredoc(input);
	else
		redirect_output(input);
	temp->operator = NONE;
	while (input->operator != NONE && input->operator != PIPE)
		input = input->next;
	if (input->operator == NONE)
		execute_cmd(temp, data);
	else
		exec_pipe(input, data);
}