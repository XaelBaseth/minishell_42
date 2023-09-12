/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:03:38 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/12 10:22:10 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	g_signal;

/*	This is called when the SIGINT (INTERRUPT or CTRL + C) signal is received.
	We check if we are in a heredoc and if so, create a new line
	inside it without exiting the heredoc input. Else, we simply
	clear the input and display a new line.
	@param sig: signal handler need a specific signature in order to
	be used as signal handler, it ensure compatibility with the
	signature for signal handler.
*/
void	sigint_handler(int sig)
{
	if (!g_signal)
		ft_putstr_fd("\n", STDERR_FILENO);
	if (g_signal)
	{
		g_signal = 1;
		rl_replace_line("", 0);
		rl_redisplay();
		rl_done = 1;
		return ;
	}
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void) sig;
}

/*	
	This is called when the SIGQUIT (QUIT or CTRL + \) signal is received.
	@param sig: signal handler need a specific signature in order to
	be used as signal handler, it ensure compatibility with the
	signature for signal handler.
*/
void	sigquit_handler(int sig)
{
	ft_putstr_fd("Quit:", STDERR_FILENO);
	ft_putnbr_fd(sig, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}
