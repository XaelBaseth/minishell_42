/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:49:01 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/11 11:53:24 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    LIBRARY: N/A

    SYNOPSIS: Count the elements in the lst list.
*/

#include "../../inc/libft.h"

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
