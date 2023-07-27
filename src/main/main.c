/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:42:03 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/27 14:48:06 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/ft_printf.h"
#include "../../inc/minishell.h"

static char	**get_input(void)
{
	char *input;

	input = readline("\033[32mminishell$\033[0m ");
	return (input);
}

void	create_processes(char *command)
{
	__pid_t	child_pid;
	int	stat_loc;

	child_pid = fork();
	if (child_pid < 0)
		panic("Fork failed.");
	if (child_pid == 0)
	{
		if (execvp(command[0], command) < 0)
			panic("The command is unknown.");
	}
	else
		waitpid(child_pid, &stat_loc, WUNTRACED);
}

int main(int argc, char **argv)
{
	char *input;

	if (argc > 1 && argv)
		panic("No arguments are needed.");
	while (1)
	{
		input = get_input();
		add_history(input);
		create_processes(input);
		/* ADD SHIT*/
		return (EXIT_SUCCESS);
	}
	
}
