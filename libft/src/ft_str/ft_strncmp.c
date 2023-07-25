/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:06:10 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/13 08:06:14 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	LIBRARY: string.h

	SYNOPSIS: 	Compare two string s1 et s2 only the first at most n bytes.
*/
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	diff;

	i = 0;
	diff = 0;
	if (n <= 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
		if (diff != 0)
			return (diff);
	}
	return (diff);
}
