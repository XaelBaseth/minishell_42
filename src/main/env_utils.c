/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:34:08 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/19 16:49:37 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_env_arr(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
		gc_free(data->envp[i++]);
	gc_free(data->envp);
	data->envp = NULL;
}

char	**env_copy(t_data *data, char **envp)
{
	char	**new_env;
	int		i;

	i = 0;
	if (data->envp)
		free_env_arr(data);
	while (envp[i])
		i++;
	new_env = (char **)gc_alloc(sizeof(char *) * (i + 1), "new_env");
	i = 0;
	while (envp[i])
	{
		new_env[i] = (char *)gc_alloc(sizeof(char) * ft_strlen(envp[i]) + 1, "new_env_line");
		ft_strlcpy(new_env[i], envp[i], ft_strlen(envp[i]) + 1);
		i++;
	}
	new_env[i] = 0;
	return (new_env);
}

void	re_store_env(t_data *data)
{
	t_env	*lst_env;
	int		i;
	int		size;

	free_env_arr(data);
	lst_env = data->lst_env;
	i = 0;
	while (lst_env)
	{
		i++;
		lst_env = lst_env->next;
	}
	data->envp = (char **)gc_alloc(sizeof(char *) * (i + 1), "new_env");
	lst_env = data->lst_env;
	i = 0;
	while (lst_env)
	{
		// voir pour gerer s'il n'y a pas de var->val / `export cricri` ne fonctionne pas !
		size = ft_strlen(lst_env->key) + ft_strlen(lst_env->val) + 2;
		data->envp[i] = (char *)gc_alloc(sizeof(char) * size, "new_env_line");
		data->envp[i] = ft_strjoin(lst_env->key, ft_strjoin("=", lst_env->val));
		i++;
		lst_env = lst_env->next;
	}
	data->envp[i] = NULL;
}
