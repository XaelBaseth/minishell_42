/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:22:56 by axel              #+#    #+#             */
/*   Updated: 2023/09/05 09:26:52 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	LIBRARY: string.h

	SYNOPSIS: 	Fills in a string with a copy of another string.
*/
#include "../../inc/libft.h"

char *ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] && i < n)
	{
		while (i < n)
			dest[i++] = '\0';
	}
	dest[i] = '\0';
	return (dest);
}
