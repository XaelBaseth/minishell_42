/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:00:06 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/07 13:45:13 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	LIBRARY: string.h

	SYNOPSIS: 	Calculate the lenght of the string pointed to by s.
*/
#include "../../inc/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
