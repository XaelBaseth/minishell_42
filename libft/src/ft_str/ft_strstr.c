/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:49:59 by axel              #+#    #+#             */
/*   Updated: 2023/09/13 08:56:13 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	LIBRARY: string.h + libbsd

	SYNOPSIS: 	Locate the first occurence of the null-terminated string
				little in the string big.
*/
#include "../../inc/libft.h"

char	*ft_strstr(char *big, char *little)
{
	int	i;
	int	j;

	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] == big[i + j])
		{
			if (little[j + 1] == '\0')
			{
				return (big + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
