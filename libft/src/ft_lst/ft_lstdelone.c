/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:57:06 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/17 09:57:11 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	LIBRARY: N/A

	SYNOPSIS: 	Free the memory passed in argument with del, then with free.
				Next memory musn't be free.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
