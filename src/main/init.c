/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:48:07 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/13 09:03:02 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	
	Returns a exit code.
	@returns `0`: exit code success.
 */
int	event(void)
{
	return (EXIT_SUCCESS);
}

/*	
	We initialize element of the data lined list before using them.
	@param *data : linked list data.
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

/*	
	Setup all the variable used for shell.
	char **envp: environment variable.
	@param *data: linked list of data.
	@param **args: linked list of args.
*/
void	setup_shell(char **envp, t_data *data)
{
	char	*path;

	init_data(data);
	store_env(envp, data);
	path = get_path(data);
	store_path(path, data);
}
