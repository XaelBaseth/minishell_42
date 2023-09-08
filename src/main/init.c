/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:48:07 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/08 09:38:53 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


/*	I have no fucking clue what it does. */
int	event(void)
{
	return (EXIT_SUCCESS);
}
/*	We initialize element of the data lined list before using them.
	@param t_data *data : linked list data.
 */
void	init_data(t_data *data)
{
	rl_event_hook = event;
	g_signal = 0;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	signal(SIGQUIT, SIG_IGN);
	data->path = NULL;
	data->lst_env = NULL;
}

/*	Setup all the variable used for shell.
	char **envp: environment variable.
	@param t_data *data: linked list of data.
	@param t_args **args: linked list of args.
*/
void	setup_shell(char **envp, t_data *data)
{
	char *path;

	init_data(data);
	store_env(envp, data);
	path = get_path(data);
	store_path(path, data);
}
