/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:01:03 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/04 14:26:05 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	check_arg_value(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i++] == '=')
			return (true);
	}
	return (false);
}

void	edit_env_var(t_data *data, char *arg, char *short_var)
{
	t_env	*lst;

	if (check_arg_value(arg) == 0)
		return ;
	lst = data->lst_env;
	while (lst)
	{
		if (ft_strcmp(lst->key, short_var) == 0)
		{
			lst->has_value = true;
			lst->val = new_env_val(lst, arg);
			return ;
		}
		lst = lst->next;
	}
}

void	new_env_var(t_data *data, char *arg)
{
	t_env	*lst;

	lst = data->lst_env;
	while (lst)
	{
		if (!lst->next)
		{
			lst->next = split_env(arg);
			return ;
		}
		lst = lst->next;
	}
}

void	export_var(t_data *data, char *arg)
{
	bool	exists;
	t_env	*lst;
	char	*short_var;

	exists = false;
	lst = data->lst_env;
	short_var = get_short_var(arg);
	while (lst)
	{
		if (ft_strcmp(lst->key, short_var) == 0)
		{
			exists = true;
			break ;
		}
		lst = lst->next;
	}
	if (exists)
		edit_env_var(data, arg, short_var);
	else
		new_env_var(data, arg);
	gc_free(short_var);
}

int		do_export(t_data *data)
{
	int	i;

	i = 1;
	if (data->args->argc == 1)
		return (set_g_status(single_export(data)));
	while (data->args->argv[i])
		export_var(data, data->args->argv[i++]);
	re_store_env(data);
	return (set_g_status(SUCCESS));
}
