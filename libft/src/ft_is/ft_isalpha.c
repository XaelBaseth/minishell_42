/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:13:53 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/11 14:13:55 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	LIBRARY: ctype.h

	SYNOPSIS: Check for alphabetic character.
*/
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
