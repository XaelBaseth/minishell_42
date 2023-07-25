/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:26:08 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/27 12:26:10 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Print a singular character on the stdout.*/
int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

/* Print out a string of characters on the stdout. */
int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/* Print out a number on the stdout. */
int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}

/* Print a single percentage on the stdout. */
int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
