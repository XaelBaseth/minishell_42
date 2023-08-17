/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:34:08 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/17 18:07:15 by cpothin          ###   ########.fr       */
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
