/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:38:49 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/03 10:14:40 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/inc/ft_printf.h"
#include "../../inc/minishell.h"

/*	Throw out an error message and exit the program. */
void	panic(char *str)
{
	gc_free_all();
	ft_printf("\033[31mError!\n%s\n\033[0m", str);
	exit(EXIT_FAILURE);
}
