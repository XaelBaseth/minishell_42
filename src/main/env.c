/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:01:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/07/28 10:40:02 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Free the variables used by the structure. */
static void	free_env(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_env)
	{
		free(data->arr_env[i].key);
		free(data->arr_env[i++].value);
	}
	free(data->arr_env);
}

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
	new_var.key = (char *)malloc(sizeof(char) * key_size + 1);
	i++;
	while (envp[i])
		i++;
	new_var.value = (char *)malloc(sizeof(char) * i - key_size + 1);
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
	data->arr_env = (t_env *)malloc(sizeof(t_env) * i + 1);
	if (!data->arr_env)
		return ;
	o = 0;
	while (o < i)
	{
		data->arr_env[o] = split_env(envp[o]);
		o++;
	}
	data->nb_env = o;
	free_env(data);
}
