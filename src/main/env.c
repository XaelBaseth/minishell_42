/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:01:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/07/27 12:07:59 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	split_env(char *envp, t_env *var)
{
	int     i;
	int     key_size;
	int     val_size;

	i = 0;
	while (envp[i] != '=')
		i++;
	key_size = i;
	printf("%d\n", key_size);
	var->key = (char *)malloc(sizeof(char) * key_size + 1);
	i++;
	while (envp[i])
		i++;
	val_size = i - key_size;
	printf("%d\n", val_size);
	var->value = (char *)malloc(sizeof(char) * val_size + 1);

	i = -1;
	while (envp[++i] != '=')
		var->key[i] = envp[i];
	var->key[i] = '\0';
	i++;
	while (envp[++i])
		var->value[i - key_size] = envp[i];
	var->value[i - key_size] = '\0';
}

void    store_env(char **envp, t_data *data)
{
	int i;
	int	o;

	i = 0;
	data->envp = envp;
	while (envp[i])
		i++;
	data->lst_env = (t_env *)malloc(sizeof(t_env) * i + 1);
	if (!data->lst_env)
	{
		printf("\n\nAAAAAAAAAAAAAAAAAAAA\n\n");
		return ;
	}
	o = 0;
	while (o < i)
	{
		// split_env(envp[o], &data->lst_env[o]);
		// printf("%s\n", data->lst_env[o].key);
		o++;
	}
	split_env("coucou=bonjour", &data->lst_env[o]);
}
