/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:03:38 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/09 08:29:26 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

pid_t	g_pid;
int		g_status;

static void	process(int sign_num)
{
	if (!kill(g_pid, sign_num))
	{
		if (sign_num == SIGQUIT)
		{
			ft_printf("Quit: \n");
			g_status = 130;
		}
		else if (sign_num == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_status = 130;
		}
	}
	else if (sign_num == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_status = 1;
	}
}

void	sigint_handler(int signum)
{
	ft_printf("PID: %d",g_pid);
	if ((signum == SIGINT || signum == SIGQUIT) && g_pid != 0)
		process(signum);
	else
	{
		if (signum == SIGINT)
		{
			ft_printf("\n");
			g_status = 1;
		}
		else if (signum == SIGQUIT)
			ft_printf("\b\b \b\b");
	}
}
