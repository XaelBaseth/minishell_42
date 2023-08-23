/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:06:04 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/23 15:47:18 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	free_node(t_env *node)
{
	gc_free(node->key);
	gc_free(node->val);
	gc_free(node);
}

static void	delete_first_lst_env(t_data *data, t_env *tmp)
{
	if (tmp->next)
		data->lst_env = data->lst_env->next;
	else
		data->lst_env = NULL;
}

static void	unset_var(t_data *data, char *arg)
{
	t_env	*tmp;
	t_env	*previous;
	int		i;

	tmp = data->lst_env;
	i = -1;
	while (tmp)
	{
		if (++i > -1 && ft_strcmp(tmp->key, arg) == 0)
		{
			if (i == 0)
			{
				delete_first_lst_env(data, tmp);
				return ;
			}
			previous->next = tmp->next;
			free_node(tmp);
			data->nb_env--;
			return ;
		}
		previous = tmp;
		tmp = tmp->next;
	}
}

void	do_unset(t_data *data)
{
	int	i;

	i = 1;
	while (data->args[i])
		unset_var(data, data->args[i++]);
	re_store_env(data);
}
