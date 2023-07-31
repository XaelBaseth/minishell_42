/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:42:03 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/31 10:43:38 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/minishell.h"

void	create_processes(char **envp)
{
	__pid_t	child_pid;
	char	**command;
	int		stat_loc;
	char	*input;

	input = get_input();
	add_history(input);
	command = get_command(input);
	child_pid = fork();
	if (child_pid < 0)
		panic("Fork failed.");
	if (child_pid == 0)
	{
		if (execve(envp[0], command, envp) < 0)
		{
			ft_printf("execve: %d\n", execve(command[0], command, envp));
			ft_printf("execvp: %d\n", execvp(command[0], command));
			//panic("The command is unknown.");
		}
	}
	else
		waitpid(child_pid, &stat_loc, WUNTRACED);
}

int main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc > 1 && argv)
		panic("No arguments are needed.");
	store_env(envp, &data);
	while (1)
	{
	 	create_processes(data.envp);
	 	/* ADD SHIT*/
	}
	return (EXIT_SUCCESS);
}

//execve(PATH | Arguments | Enviro)
//On a le PATH avec getenv()

/*	PARSING	*/
//Gerer les parentheses
//Gerer les espaces.
//Recuperer les commandes
//Gere les operateurs
//Executer