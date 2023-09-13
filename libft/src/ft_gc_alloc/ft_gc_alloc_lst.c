/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_alloc_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:46:17 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/13 08:54:10 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_gc_alloc.h"

void	lst_add_back(t_alloc_ptr *lst, t_alloc_ptr *new)
{
	t_alloc_ptr	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	tmp->next = new;
}

/*	This function defines a new node. */
t_alloc_ptr	*new_node(size_t size, char *name)
{
	t_alloc_ptr	*lst;

	lst = malloc(sizeof(t_alloc_ptr));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->size = size;
	lst->name = name;
	lst->addr = malloc(size);
	return (lst);
}

/*	This function free a node in the list. */
void	free_elem(t_alloc_ptr *element)
{
	if (element)
	{
		free(element->addr);
		free(element);
	}
}

/*	This function frees and remove the address of the given node in the
	list. */
t_alloc_ptr	*remove_address(int index, t_alloc_ptr *lst)
{
	t_alloc_ptr	*new_list;
	t_alloc_ptr	*past;

	if (!index)
	{
		new_list = lst->next;
		free_elem(lst);
		return (new_list);
	}
	new_list = lst;
	while (index)
	{
		past = lst;
		lst = lst->next;
		index--;
	}
	past->next = lst->next;
	free_elem(lst);
	return (new_list);
}

/*	This function display a list of every node within the garbage collector. */
void	print_address(void)
{
	int			i;
	t_alloc_ptr	*lst;

	i = 0;
	lst = addr_save(NULL, 1);
	ft_printf("\tGarbage Collector Address:\n");
	ft_printf("------------------------\n\n");
	ft_printf("\033[1m[Index]\033[0m\t->\t\033[32m[Address]\033[34m\t\t[Name]\
		\033[0m\t->\t[Size]\n");
	while (lst)
	{
		ft_printf("\033[1m[%d]\033[0m\t->\t\033[32m[%p]\033[34m\t[%s]\
			\033[0m->[%d]\n", i++, lst->addr, lst->name, lst->size);
		lst = lst->next;
	}
	ft_printf("------------------------\n");
}
