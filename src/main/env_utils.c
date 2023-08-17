/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:34:08 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/17 10:01:41 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_env	*ft_envlast(t_env *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_envadd_back(t_env *lst, t_env *new)
{
	t_env	*last;
	t_env	*head;

	if (lst)
	{
		head = lst;
		last = ft_envlast(lst);
		last->next = new;
		lst = head;
	}
	else
		lst = new;
}