/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:27:56 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/14 13:27:57 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	LIBRARY: N/A

	SYNOPSIS: Writes a number on the file descriptor.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = (unsigned int)(-n);
	}
	else
		num = (unsigned int)n;
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		num %= 10;
	}
	ft_putchar_fd(num + '0', fd);
}
