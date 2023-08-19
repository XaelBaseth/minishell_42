/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:01:03 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/19 16:47:47 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	edit_env_var(t_data *data, char *arg, char *short_var)
{
	t_env	*lst;
	t_env	*next;
	t_env	*previous;

	lst = data->lst_env;
	while (lst)
	{
		if (ft_strncmp(lst->key, short_var, ft_strlen(lst->key)) == 0)
		{
			next = lst->next;
			gc_free(lst->key);
			gc_free(lst->val);
			lst->next = NULL;
			lst->previous = NULL;
			gc_free(lst);
			lst = split_env(arg);
			previous->next = lst;
			lst->next = next;
			return ;
		}
		previous = lst;
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

// export cricri		->		cricri
// export cricri=42		->		cricri=42
// export cricri		->		cricri=42
void	export_var(t_data *data, char *arg)
{
	bool	exists;
	int		i;
	t_env	*lst;
	char	*short_var;

	exists = false;
	lst = data->lst_env;
	i = 0;
	while (arg[i] != '=' && arg[i] != '\0')
		i++;
	short_var = (char *)gc_alloc(sizeof(char) * i + 1, "short_env_var");
	ft_strlcpy(short_var, arg, i + 1);
	while (lst && i++)
	{
		if (ft_strncmp(lst->key, short_var, ft_strlen(lst->key)) == 0)
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

void	do_export(t_data *data)
{
	int	i;

	i = 1;
	while (data->args[i])
		export_var(data, data->args[i++]);
	re_store_env(data);
}