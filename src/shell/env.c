/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:01:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/03 10:05:34 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Split the environment variables through a 'key
	and value' variable setup in the t_env structure. */
static t_env	split_env(char *envp)
{
	t_env	new_var;
	int     i;
	int     key_size;

	i = 0;
	// if (!envp)
	//     return (new_var); <- protection if something fails!
	while (envp[i] != '=')
		i++;
	key_size = i;
	new_var.key = (char *)gc_alloc(sizeof(char) * key_size + 1, "env: var_key");
	i++;
	while (envp[i])
		i++;
	new_var.value = (char *)gc_alloc(sizeof(char) * i - key_size + 1, "env: var_value");
	if (!new_var.key || !new_var.value)
		return (new_var);
	i = -1;
	while (envp[++i] != '=')
		new_var.key[i] = envp[i];
	new_var.key[i] = '\0';
	while (envp[++i])
		new_var.value[i - key_size - 1] = envp[i];
	new_var.value[i - key_size - 1] = '\0';
	return (new_var);
}
/*	Duplicates and store the environment variables through a 'key
	and value' variable setup in the t_env structure. */
void	store_env(char **envp, t_data *data)
{
	int i;
	int	o;

	i = 0;
	data->envp = envp;
	while (envp[i])
		i++;
	data->nb_env = i;
	data->arr_env = (t_env *)gc_alloc(sizeof(t_env) * i + 1, "env: var_array");
	if (!data->arr_env)
		return ;
	o = 0;
	while (o < i)
	{
		data->arr_env[o] = split_env(envp[o]);
		//ft_printf("%s\n", data->arr_env[o].key);
		//ft_printf("%s\n", data->arr_env[o].value);
		o++;
	}
}

void	print_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		printf("%s\n", data->envp[i]);
		i++;
	}
}