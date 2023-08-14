/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:39:45 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/11 11:52:47 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	LIBRARY: string.h

	SYNOPSIS: Compare the first n bytes of the memory areas pointed by
				s1 and s2.
*/
#include "../../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
