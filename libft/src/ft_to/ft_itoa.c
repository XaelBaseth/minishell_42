/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:56:24 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/07 09:48:43 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	LIBRARY: N/A

	SYNOPSIS: Returns a string from a n int.
*/

#include "../../inc/libft.h"

static size_t	ft_number_size(int number)
{
	size_t	len;

	len = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		len += 1;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	size_t			len;

	len = ft_number_size(n);
	str = (char *)gc_alloc(sizeof(char) * (len + 1), "ft_itoa");
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}
