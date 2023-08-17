/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:42:03 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/17 13:12:24 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	event(void)
{
	return (EXIT_SUCCESS);
}

/*	On initialise pour eviter problemes de memoire */
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
	t_args	*args;
	char 	*path;
	char	*input;

	if (argc > 1 && argv)
		panic("No arguments are needed.");
	init_data(&data);
	store_env(envp, &data);
	path = get_path(&data);
	set_pwd(&data);
	store_path(path, &data);
	while (1)
	{
		input = get_input();
		if (!valid_input(input))
			continue ;
		add_history(input);
		args = parser(input);
		// Print the parsed arguments
		printf("##########################\n");
        printf("Printing parsed arguments:\n");
        t_args *temp = args;
        while (temp)
        {
            for (int i = 0; temp->argv[i]; i++)
            {
                printf("Argument %d: %s\n", i, temp->argv[i]);
            }
            printf("Operator: %d\n", temp->operator);
            printf("----------\n");
            temp = temp->next;
        }
		//END OF PRINTING
		create_processes(args, &data);
		clean_parsed(&args, &data);
	}
	gc_free_all();
	return (EXIT_SUCCESS);
}

