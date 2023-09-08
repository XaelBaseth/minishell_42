/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:42:03 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/07 17:48:55 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void print_args(t_args *args)
{
	int i = 0;

	while (args)
	{
		ft_printf("ARGC: %d\n", args->argc);
		while (args->argv[i])
			ft_printf("%s\n", args->argv[i++]);
		ft_printf("NEXT\n");
		args = args->next;
	}
}

static void	process_data(t_data *data)
{
	argc_post_parsing(data->args);
	create_processes(data->args, data);
	clean_parsed(data->args, data);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*input;

	if (argc > 1 && argv)
		panic("No arguments are needed.");
	setup_shell(envp, &data);
	while (1)
	{
		input = get_input();
		if (!input)
			continue ;
		if (!valid_input(input))
			continue ;
		add_history(input);
		input = expand(&data, input);
		if (!input[0])
		{
			free(input);
			continue ;
		}
		data.args = parser(input);
		process_data(&data);
	}
	gc_free_all();
	return (EXIT_SUCCESS);
}
