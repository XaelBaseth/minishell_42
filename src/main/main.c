/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:42:03 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/07 16:51:26 by cpothin          ###   ########.fr       */
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
		args = parser(input);
		// print_args(args);
		data.args = args;
		create_processes(args, &data);
		clean_parsed(&args, &data);
	}
	gc_free_all();
	return (EXIT_SUCCESS);
}
