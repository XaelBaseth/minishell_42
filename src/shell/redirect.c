/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:37:22 by axel              #+#    #+#             */
/*   Updated: 2023/09/19 08:48:21 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shell.h"
/*	
	Redirect the input of a command into the file via the '<' operator.
	@param t_args *input: command that has been inputed.
*/
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

/*	
	Check the operator used and create or replace a document if '>', or
	append a document if '>>'.
	@param t_args *input: command that has been inputed.
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

/*	
	Check for the redirection symbol, or pipe, and execute the correct command.
	@param t_args *input: command inputed with the operator.
	@param t_data *data : environment in which the command is executed.
*/
void	exec_redirect(t_args *input, t_data *data)
{
	t_args	*temp;

	temp = input;
	while (input->operator != NONE && input->operator != PIPE)
	{
		if (input->operator == REDIR_INPUT)
			redirect_input(input);
		else if (input->operator == REDIR_INPUT_UNTIL
			&& input->next->operator == REDIR_INPUT_UNTIL)
		{
			exec_multiple_heredoc(input, data);
			break ;
		}
		else if (input->operator == REDIR_INPUT_UNTIL)
			exec_heredoc(input, data);
		else
			redirect_output(input);
		input = input->next;
	}
	temp->operator = NONE;
	if (input->operator == NONE)
		execute_cmd(temp, data);
	else
		exec_pipe(input, data);
}
