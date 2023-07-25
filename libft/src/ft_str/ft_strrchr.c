/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:42:06 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/12 13:42:19 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	LIBRARY: string.h

	SYNOPSIS: 	Retunrs a pointer to the first occurence of the character c
				in the string s.
*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	lenght;

	lenght = ft_strlen(s);
	while (lenght >= 0)
	{
		if (s[lenght] == (char)c)
			return ((char *)s + lenght);
		lenght--;
	}
	return (NULL);
}
