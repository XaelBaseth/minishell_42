/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:58:32 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/11 11:49:53 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	LIBRARY: string.h

	SYNOPSIS: 	Returns a pointer to the first occurence of the character c
				in the string s.
*/
#include "../../inc/libft.h"

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
