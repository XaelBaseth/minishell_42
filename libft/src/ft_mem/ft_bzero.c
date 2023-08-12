/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:57:18 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/11 11:52:54 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	LIBRARY: strings.h

	SYNOPSIS: 	Erases the data in the n bytes of the memory starting
				at the location pointed to by s, by writing \0 to that
				are.
*/
#include "../../inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = (unsigned char *)s;
	while (i++ < n)
		*a++ = 0;
}
