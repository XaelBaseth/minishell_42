/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:34:08 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/13 08:43:49 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shell.h"

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
		new_env[i] = (char *)gc_alloc(sizeof(char)
				* ft_strlen(envp[i]) + 1, "new_env_line");
		ft_strlcpy(new_env[i], envp[i], ft_strlen(envp[i]) + 1);
		i++;
	}
	new_env[i] = 0;
	return (new_env);
}

char	*create_env_from_lst(t_env *lst_env)
{
	int		size;
	char	*env;

	if (lst_env->val)
		size = ft_strlen(lst_env->key) + ft_strlen(lst_env->val) + 2;
	else
		size = ft_strlen(lst_env->key) + 2;
	env = (char *)gc_alloc(sizeof(char) * size, "new_env_line");
	if (lst_env->has_value == true)
		env = ft_strjoin(lst_env->key, ft_strjoin("=", lst_env->val));
	else
		env = ft_strdup(lst_env->key);
	return (env);
}

void	re_store_env(t_data *data)
{
	t_env	*lst_env;
	int		i;

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
		data->envp[i] = create_env_from_lst(lst_env);
		i++;
		lst_env = lst_env->next;
	}
	data->envp[i] = NULL;
}

char	*get_short_var(char *arg)
{
	char	*str;
	int		i;

	i = 0;
	while (arg[i] != '=' && arg[i] != '\0')
		i++;
	str = (char *)gc_alloc(sizeof(char) * i + 1, "short_env_var");
	ft_strlcpy(str, arg, i + 1);
	return (str);
}
