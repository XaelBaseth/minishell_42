/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_single.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:13:55 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/13 09:11:58 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shell.h"

t_env	*find_min_value(t_data *data)
{
	t_env	*lst;
	t_env	*min_lst;

	lst = data->lst_env;
	min_lst = data->lst_env;
	while (lst)
	{
		if (ft_strcmp(lst->key, min_lst->key) < 0)
			min_lst = lst;
		lst = lst->next;
	}
	return (min_lst);
}

t_env	*find_next_min_value(t_data *data, t_env *cur_lst)
{
	t_env	*lst;
	t_env	*min_lst;
	int		min;
	int		cur_val;

	lst = data->lst_env;
	min_lst = cur_lst;
	min = 1000;
	while (lst)
	{
		cur_val = ft_strcmp(lst->key, min_lst->key);
		if (cur_val < min && ft_strcmp(lst->key, cur_lst->key) > 0)
		{
			min_lst = lst;
			min = 0;
		}
		lst = lst->next;
	}
	if (min == 1000)
		return (NULL);
	return (min_lst);
}

int	single_export(t_data *data)
{
	t_env	*last_value;

	last_value = find_min_value(data);
	while (last_value != NULL)
	{
		ft_printf("declare -x %s=\"%s\"\n", last_value->key, last_value->val);
		last_value = find_next_min_value(data, last_value);
	}
	return (SUCCESS);
}
