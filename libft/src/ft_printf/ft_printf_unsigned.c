/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:27:34 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/11 11:51:37 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include "../../inc/libft.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)gc_alloc(sizeof(char) * (len + 1), "ft_printf: uitoa");
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_printf_unsigned(unsigned int n)
{
	int		print_len;
	char	*num;

	print_len = 0;
	if (n == 0)
		print_len += ft_printchar('0');
	else
	{
		num = ft_uitoa(n);
		print_len += ft_printstr(num);
	}
	return (print_len);
}
