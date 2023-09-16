/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:40:37 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/16 13:04:09 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtins.h"

/*
	Free the allocated memory of the `envp` array.
	@param `*node`: Variable of the copy array to free.
*/
void	free_lst_node(t_env *node)
{
	gc_free(node->key);
	gc_free(node->val);
	node->next = NULL;
	node->previous = NULL;
	gc_free(node);
}

/*
	Extract and set a new value for an environment variable.
	@param `*env`: copy of the environment of minishell
	@param `*arg`: value to add to the environmnent of minishell.
	@returns `*new_val` - new variable added to the environmnent of minishell. 
*/
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

/*
	Return the value of a specific environmnent variable.
	@param `*lst`: copy of the environment of minishell
	@param `*var_name`:
	@returns `temp->val` or `NULL` - Either a variable value or
	Null.
*/
char	*get_env_value(t_env *lst, char *var_name)
{
	t_env	*temp;

	temp = lst;
	while (temp != NULL)
	{
		if (ft_strcmp(var_name, temp->key) == 0)
			return (temp->val);
		temp = temp->next;
	}
	return (NULL);
}
