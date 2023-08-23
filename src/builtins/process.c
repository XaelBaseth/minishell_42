/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:08:31 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/23 15:24:26 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	create_processes(t_data *data)
{
	int	stat_loc;

	if (!builtins(data) && fork() == 0)
	{
		execute_cmd(data);
	}
	waitpid(-1, &stat_loc, WUNTRACED);
}
