/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:51:09 by axel              #+#    #+#             */
/*   Updated: 2023/08/22 14:42:00 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Set up the process to redirect its standard output to the write end of a
	pipe.
	t_args *input : input command of the user.
	t_data *data : environment in which the command would be executed.
	int pdes[2] : pipe file descriptors.
*/
static void	left_side(t_args *input, t_data *data, int pdes[2])
{
	close(STDOUT_FILENO);
	dup(pdes[1]);
	close(pdes[0]);
	close(pdes[1]);
	execute_cmd(input, data);
}
/*	Set up the process to redirect its standard input to the read end of a
	pipe.
	t_args *input : input command of the user.
	t_data *data : environment in which the command would be executed.
	int pdes[2] : pipe file descriptors.
*/
static void	right_side(t_args *input, t_data *data, int pdes[2])
{
	close(STDIN_FILENO);
	dup(pdes[0]);
	close(pdes[0]);
	close(pdes[1]);
	execute_cmd(input, data);
}

/*	Handles the execution of commands using pipes, creating a child process
	to handle the left side and the parent process to handle the right side.
	t_args *input : input command of the user.
	t_data *data : environment in which the command would be executed.
*/
void	exec_pipe(t_args *input, t_data *data)
{
	pid_t	child_pid;
	int		pipedes[2];
	int		temp_status;

	input->operator = NONE;
	if (pipe(pipedes) == -1)
		panic(PIPE_ERR);
	child_pid = fork();
	if (child_pid == -1)
		panic(FORK_ERR);
	if (child_pid == 0)
		left_side(input, data, pipedes);
	right_side(input->next, data, pipedes);
	close(pipedes[0]);
	close(pipedes[1]);
	waitpid(child_pid, &temp_status, 0);
}