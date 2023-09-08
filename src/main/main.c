/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:42:03 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/08 14:21:32 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void print_args(t_args *args)
{
	int i;

	ft_printf("\033[34m#####################################\033[0m\n\n\n");
	while (args)
	{
		i = 0;
		ft_printf("\033[34mARGC: %d\033[0m\n", args->argc);
		while (args->argv[i])
			ft_printf("\033[34mARGV: %s\033[0m\n", args->argv[i++]);
		ft_printf("\033[34mOPERATOR : %d\033[0m\n\n\n", args->operator);
		if (args == NULL)
			ft_printf("\033[34m~No more args~033[0m\n");
		args = args->next;
	}
	ft_printf("\033[34m#####################################\033[0m\n");
}

static void	process_data(t_data *data)
{
	argc_post_parsing(data->args);
	print_args(data->args);
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
