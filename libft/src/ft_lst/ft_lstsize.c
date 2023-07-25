/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:49:01 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/17 08:49:05 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
    LIBRARY: N/A

    SYNOPSIS: Count the elements in the lst list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
