/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:01:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/21 17:07:43 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	char_is_equal(char c)
{
	if (c == '=')
		return (true);
	else
		return (false);
}

/*	Split the environment variables through a 'key
	and value' variable setup in the t_env structure. */
t_env	*split_env(char *envp)
{
	t_env	*new_var;
	int		i;
	int		key_size;

	i = 0;
	new_var = (t_env *)gc_alloc(sizeof(t_env), "env_var");
	new_var->next = NULL;
	new_var->previous = NULL;
	while (envp[i] && envp[i] != '=')
		i++;
	new_var->has_value = char_is_equal(envp[i]);
	key_size = i;
	new_var->key = (char *)gc_alloc(sizeof(char) * key_size + 1, "env_key");
	ft_strlcpy(new_var->key, envp, key_size + 1);
	if (!envp[i])
	{
		new_var->val = (char *)gc_alloc(sizeof(char) * 1, "env_val");
		new_var->val[0] = 0;
		return (new_var);
	}
	while (envp[i])
		i++;
	new_var->val = ft_strdup_range(envp, key_size + 1, ft_strlen(envp));
	return (new_var);
}

/*	Duplicates and stores the environment variables through a 'key
	and value' variable setup in the t_env structure. */
void	store_env(char **envp, t_data *data)
{
	int	i;
	t_env	*head;

	i = 0;
	data->envp = envp;
	while (envp[i])
		i++;
	data->nb_env = i;
	i = 0;
	while (i < data->nb_env)
	{
		if (data->lst_env)
		{
			data->lst_env->next = split_env(envp[i++]);
			data->lst_env = data->lst_env->next;
		}
		else
		{
			data->lst_env = split_env(envp[i++]);
			head = data->lst_env;
		}
	}
	data->lst_env = head;
}

/*	Print out a copy of the ENV data cloned into envp. */
void	print_env(t_data *data)
{
	int	i = 0;

	if (data->args[1])
	{
		ft_printf("env: %s: No arguments are authorized\n", data->args[1]);
		return ;
	}
	while (data->envp[i])
	{
		ft_printf("%s\n", data->envp[i++]);
	}
}

// void	update_env(t_data *data)
// {
// 	t_env	*head;
// 	char	**new_env;
// 	int		i;

// 	i = 0;
// 	head = data->arr_env;
// 	while (head->next) // ajouter && i++ pour economiser des lignes
// 	{
// 		head = head->next;
// 		i++;
// 	}
// 	new_env = (char **)gc_alloc(sizeof(char *) * i + 1, );
// 	data->nb_env = i;
// 	head = data->arr_env;
// 	i = -1;
// 	while (++i < data->nb_env)
// 	{
		
// 	}
// }
