/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:40:37 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/21 16:49:51 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_lst_node(t_env *node)
{
		gc_free(node->key);
		gc_free(node->val);
		node->next = NULL;
		node->previous = NULL;
		gc_free(node);
}

char	*new_env_val(t_env *env, char *arg)
{
	char	*new_val;
	int		i;
	int		start;

	i = 0;
	gc_free(env->val);
	while (arg[i] && arg[i] != '=')
		i++;
	if (!arg[i])
		return (NULL);
	start = i;
	while (arg[i])
		i++;
	new_val = ft_strdup_range(arg, start + 1, i);
	return (new_val);
}