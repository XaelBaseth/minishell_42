/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:06:04 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/16 13:04:30 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtins.h"

/*
	Free the allocated memory of the given node.
	@param `*node` : element of an array.
*/
static void	free_node(t_env *node)
{
	gc_free(node->key);
	gc_free(node->val);
	gc_free(node);
}

/*
	Deletes the first node in an environmnent list.
	@param `*data`: environment of minishell.
	@param `*tmp`: environment list of minishell.
*/
static void	delete_first_lst_env(t_data *data, t_env *tmp)
{
	if (tmp->next)
		data->lst_env = data->lst_env->next;
	else
		data->lst_env = NULL;
}

/*
	Removes an element of the environment list.
	@param `*data`: environment of minishell.
	@param `*arg`: element to be removed.
*/
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

/*
	Unsets the specified environment variables. If they exist,
	they are removed. If they don't, nothing happens.
	@param `*data`: environment of minishell.
	@returns `g_status` - int of the exit code of the command.
*/
int	do_unset(t_data *data)
{
	int	i;

	i = 1;
	while (data->args->argv[i])
		unset_var(data, data->args->argv[i++]);
	re_store_env(data);
	return (set_g_status(SUCCESS));
}
