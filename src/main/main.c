/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:42:03 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/29 16:43:18 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*void	create_processes(char *command)
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
}*/

/*	On initialise pour eviter problemes de memoire */
void	init_data(t_data *data)
{
	data->input = NULL;
}

int main(int argc, char **argv, char **envp)
{
	t_data	data;
	// char *input;

	if (argc > 1 && argv)
		panic("No arguments are needed.");
	init_data(&data);
	store_env(envp, &data);
	while (1)
	{
		if (data.input) // on free sinon ca leak pour chaque ligne malloc.
			free(data.input);
		data.input = get_input();
		// add_history(data.input);
		// create_processes(data.input);
		/* ADD SHIT*/

		// si la ligne est vide, on ne quitte pas le programme.
		if (!data.input || line_is(&data, ""))
			continue ;
		// on quitte le programme si on ecrit "exit", c'est juste pour tester.
		if (line_is(&data, "exit"))
		{
			free_all(&data);
			return (EXIT_SUCCESS);
		}
	}
	
}
