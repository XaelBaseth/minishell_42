/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:46:13 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/13 08:54:09 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_gc_alloc.h"

/*	This  function adds a new node at the end of the list or creating the
	list. */
t_alloc_ptr	*addr_save(t_alloc_ptr *ptr, int code)
{
	static t_alloc_ptr	*lst;

	if (!code)
		lst = ptr;
	else if (ptr)
		lst_add_back(lst, ptr);
	return (lst);
}

/* This function increase or decrease the list size accordingly to the
	code given. */
int	lst_lenght(int code)
{
	int			ret;
	static int	lenght;

	ret = lenght;
	if (code == 1)
		lenght++;
	else if (code == 2)
		lenght = 0;
	else if (code == 3)
		lenght--;
	return (ret);
}

/*	This function free all the memory allocation added on the list. */
void	gc_free_all(void)
{
	t_alloc_ptr	*lst;
	t_alloc_ptr	*tmp;

	lst = addr_save(NULL, 1);
	while (lst)
	{
		tmp = lst->next;
		free(lst->addr);
		free(lst);
		lst = tmp;
	}
	lst_lenght(2);
}

/*	This funcion free one memory allocation added on the list via its
	adress. */
void	gc_free(void *addr)
{
	int			index;
	t_alloc_ptr	*lst;

	index = 0;
	lst = addr_save(NULL, 1);
	while (lst)
	{
		if (lst->addr == addr)
			break ;
		lst = lst->next;
		index++;
	}
	if (!lst)
		return ;
	lst = remove_address(index, addr_save(NULL, 1));
	addr_save(lst, 0);
	lst_lenght(3);
}

/*	This function adds a memory allocation onto the list. */
void	*gc_alloc(size_t size, char *name)
{
	t_alloc_ptr	*lst;

	lst = new_node(size, name);
	if (!lst)
		return (NULL);
	if (lst_lenght(1) == 0)
		addr_save(lst, 0);
	else
		addr_save(lst, 1);
	return (lst->addr);
}
