/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:41:52 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/03 10:33:45 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Handles the builtins commands. */
bool	builtins(t_data *data)
{
	if (line_is(data, "env"))
		print_env(data);
	else
		return (false);
	return (true);
}