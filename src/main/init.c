/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:48:07 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/30 08:59:47 by acharlot         ###   ########.fr       */
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
	g_signal.stop_heredoc = 0;
	g_signal.in_cmd = 0;
	g_signal.in_heredoc = 0;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	data->path = NULL;
	data->lst_env = NULL;
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
	// set_pwd(data);
	store_path(path, data);
	*args = NULL;
}