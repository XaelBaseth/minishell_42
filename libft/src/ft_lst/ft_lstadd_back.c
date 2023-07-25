/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:37:24 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/17 09:37:27 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	LIBRARY: N/A

	SYNOPSIS: Create a new element at the end of the list, or create a list.
*/
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}
