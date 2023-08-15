/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:42:03 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/15 14:00:10 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	On initialise pour eviter problemes de memoire */

int	event(void)
{
	return (EXIT_SUCCESS);
}

void	init_data(t_data *data)
{
	rl_event_hook = event;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGQUIT, sigint_handler);
	signal(SIGINT, sigint_handler);
	data->path = NULL;
	g_pid = 0;
}

int main(int argc, char **argv, char **envp)
{
	t_data	data;
	char 	*path;

	if (argc > 1 && argv)
		panic("No arguments are needed.");
	init_data(&data);
	store_env(envp, &data);
	//print_env(&data);
	path = get_path(&data);
	set_pwd(&data);
	store_path(path, &data);
	//print_path(&data);
	//print_addr(&data);
	while (1)
	{
		if (data.input) // on free sinon ca leak pour chaque ligne malloc.
			free(data.input);
		data.input = get_input();
		add_history(data.input);
		// execute_in_path(&data);
		// create_processes(data.input);
		/* ADD SHIT*/

		/* si la ligne est vide, on ne quitte pas le programme.
		Si on ecrit "env" ou "exit", on lance les commandes associees.
		Ca ne remplace pas le systeme de parsing, mais ca fonctionne */
		if (!data.input || line_is(&data, ""))
			continue ;
		if (!builtins(&data))
		{
			free_all(&data);
			gc_free_all();
			return (EXIT_FAILURE);
		}
	}
	free_all(&data);
	gc_free_all();
	return (EXIT_SUCCESS);
}

