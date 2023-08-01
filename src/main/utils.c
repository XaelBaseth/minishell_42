/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:38:49 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/01 08:25:38 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/ft_printf.h"
#include "../../inc/minishell.h"

/*	Throw out an error message and exit the program. */
void	panic(char *str)
{
	ft_printf("\033[31mError!\n%s\n\033[0m", str);
	exit(EXIT_FAILURE);
}

/*	Free the allocated memory of the arr_env from the
	structures.	*/
void	free_all_struct(t_data *data)
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