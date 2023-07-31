/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:00:03 by cpothin           #+#    #+#             */
/*   Updated: 2023/07/29 16:37:51 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// free everything
void	free_all(t_data *data)
{
	int	i;

	if (data->input)
		free(data->input);
	if (data->nb_env > 0)
	{
		i = 0;
		while (i < data->nb_env)
		{
			free(data->arr_env[i].key);
			free(data->arr_env[i++].value);
		}
		free(data->arr_env);
	}
}