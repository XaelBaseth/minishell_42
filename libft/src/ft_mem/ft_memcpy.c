/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:37:13 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/11 11:19:10 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	LIBRARY: string.h

	SYNOPSIS: Copies n bytes from memory area pointed by src to memore area 
				pointed by dest. The memory areas must not overlap.
*/
#include "../../inc/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
