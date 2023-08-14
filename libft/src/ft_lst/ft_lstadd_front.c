/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:35:45 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/11 11:53:02 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	LIBRARY: N/A

	SYNOPSIS: 	Add the element new at the beginnig of the lst list, or
				create it.
*/
#include "../../inc/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
	}
	*lst = new;
}
