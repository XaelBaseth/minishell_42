/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:42:03 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/18 10:53:58 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_data	data;
	t_args	*args;
	char	*input;

	if (argc > 1 && argv)
		panic("No arguments are needed.");
	setup_shell(envp, &data, &args);
	while (1)
	{
		input = get_input();
		if (!valid_input(input))
			continue ;
		add_history(input);
		if (!input[0])
		{
			free(input);
			continue ;
		}
		args = parser(input);
		data.args = args;
		create_processes(args, &data);
		clean_parsed(&args, &data);
	}
	gc_free_all();
	return (EXIT_SUCCESS);
}

