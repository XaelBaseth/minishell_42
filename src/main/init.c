/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:48:07 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/18 11:00:27 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	I have no fucking clue what it does. */
int	event(void)
{
	return (EXIT_SUCCESS);
}
/*	We initialize element of the data lined list before using them.
	t_data *data : linked list data.
 */
void	init_data(t_data *data)
{
	rl_event_hook = event;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGQUIT, sigint_handler);
	signal(SIGINT, sigint_handler);
	data->path = NULL;
	g_pid = 0;
}

/*	Setup all the variable used for shell.
	char **envp: environment variable.
	t_data *data: linked list of data.
	t_args **args: linked list of args.
*/
void	setup_shell(char **envp, t_data *data, t_args **args)
{
	char *path;

	init_data(data);
	store_env(envp, data);
	path = get_path(data);
	set_pwd(data);
	store_path(path, data);
	*args = NULL;
}