/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:42:45 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/11 11:49:46 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	LIBRARY: N/A

	SYNOPSIS: Applies a f function to a given s string but does not return
				another string, unlike ft_strmapi.
*/
#include "../../inc/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
