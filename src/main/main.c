/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:42:03 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/15 14:30:25 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	
	Prints the arguments divided by their places in the t_args structure.
	@param *args : command inputed by the user.
*/
void	print_args(t_args *args)
{
	int	i;

	ft_printf("\033[34m#####################################\033[0m\n\n\n");
	while (args)
	{
		i = 0;
		ft_printf("\033[34mARGC: %d\033[0m\n", args->argc);
		while (args->argv[i])
			ft_printf("\033[34mARGV: %s\033[0m\n", args->argv[i++]);
		ft_printf("\033[34mOPERATOR : %d\033[0m\n\n\n", args->operator);
		args = args->next;
	}
	ft_printf("\033[34m#####################################\033[0m\n");
}

/*	
	Processes the data used by the minishell in an executor and clean the
	input.
	@param *data: data used by the minishell.	
*/
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
