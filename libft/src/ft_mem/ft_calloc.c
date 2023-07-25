/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:26:17 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/14 08:26:24 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	LIBRARY: stdlib.h

	SYNOPSIS: 	Allocate memory for an array of nmemb elements of size bytes
				and returns a pointer to the allocated memory.
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	size_t	total_size;

	total_size = nmemb * size;
	if ((nmemb == SIZE_MAX) || (size == SIZE_MAX)
		|| (total_size > SIZE_MAX))
	{
		return (NULL);
	}
	dest = malloc(total_size);
	if (dest == NULL)
	{
		return (NULL);
	}
	ft_memset(dest, 0, total_size);
	return (dest);
}
