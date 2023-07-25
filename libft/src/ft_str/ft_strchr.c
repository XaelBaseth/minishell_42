/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:58:32 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/12 12:58:34 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	LIBRARY: string.h

	SYNOPSIS: 	Returns a pointer to the first occurence of the character c
				in the string s.
*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	while (*s && *s != a)
		s++;
	if (*s == a)
		return ((char *)s);
	return (0);
}
