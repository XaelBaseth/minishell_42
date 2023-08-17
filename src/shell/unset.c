/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:06:04 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/17 18:22:36 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_node(t_env *node)
{
	gc_free(node->key);
	gc_free(node->val);
	gc_free(node);
}

void	unset_var(t_data *data, char *arg)
{
	// on itere dans a liste chainee
	// si on trouve la valeur
	// on la supprime
	// sinon, on ne fait rien (pas de message, que ca fonctionne ou pas)
	t_env	*tmp;
	t_env	*next;
	t_env	*previous;
	int		i;

	tmp = data->arr_env;
	next = data->arr_env;
	i = 0;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, arg, ft_strlen(arg)) == 0)
		{
			if (i == 0)
			{
				if (tmp->next)
					data->arr_env = data->arr_env->next;
				else
					data->arr_env = NULL;
				return ;
			}
			previous->next = tmp->next;
			free_node(tmp);
			return ;
		}
		i++;
		previous = tmp;
		tmp = tmp->next;
	}
	(void)next;
}

void	do_unset(t_data *data)
{
	int	i;

	i = 1;
	while (data->args[i])
		unset_var(data, data->args[i++]);

	// on recree la variable data->envp apres avoir tout unset
}