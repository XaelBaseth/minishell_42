/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:53:59 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/13 10:54:04 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	LIBRARY: string.h

	SYNOPSIS: 	Returns a pointer to a new string which is a duplicated of
				the string s.Memory is obtained with malloc and has to be
				freed with free.
*/
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	size_t	i;
	char	*s_copy;

	s_len = ft_strlen(s);
	s_copy = malloc((s_len + 1) * sizeof(char));
	if (!s_copy)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		s_copy[i] = s[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
