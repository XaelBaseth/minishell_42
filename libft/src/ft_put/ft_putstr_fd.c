/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:35:11 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/14 12:35:13 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	LIBRARY: N/A

	SYNOPSIS: Writes a string s on the file descriptor fd.
*/
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

