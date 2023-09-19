/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:46:46 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/19 08:47:35 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shell.h"

/*
	Close the pipe handling the heredocuments.
	@param *fd: pipe that needs to be closed.
*/
void	close_heredoc(int *fd)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

/*
 	Allows to input multiple line lines until a line containing the 
	delimiter is seen via the '<<' input.
	@param *input: command that has been inputed.
	@param *data: environmnent of the minishell.
*/
void	exec_heredoc(t_args *input, t_data *data)
{
	char	*buffer;
	char	*expanded_buffer;
	int		fd[2];

	pipe(fd);
	while (1)
	{
		buffer = readline("\033[32m$> \033[0m");
		if (!buffer)
		{
			ft_putendl_fd("minishell: HEREDOC needs a delimitor to exit.",
				STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		if (ft_strcmp(buffer, input->next->argv[0]) == 0)
			break ;
		expanded_buffer = expand(data, buffer);
		ft_putendl_fd(expanded_buffer, fd[1]);
		free(buffer);
	}
	close_heredoc(fd);
}

/*
	Handle several heredocuments on a single command line.
	@param *input: command that has been inputed.
	@param *data: environmnent of the minishell.
*/
void	exec_multiple_heredoc(t_args *input, t_data *data)
{
	char	*buffer;
	char	*expanded_buffer;
	int		fd[2];

	pipe(fd);
	while (input->operator == REDIR_INPUT_UNTIL)
	{
		while (1)
		{
			buffer = readline("\033[32m$> \033[0m");
			if (!buffer)
			{
				ft_putendl_fd("minishell: HEREDOC needs a delimitor to exit.",
					STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
			if (ft_strcmp(buffer, input->next->argv[0]) == 0)
				break ;
			expanded_buffer = expand(data, buffer);
			ft_putendl_fd(expanded_buffer, fd[1]);
			free(buffer);
		}
		input = input->next;
	}
	close_heredoc(fd);
}
