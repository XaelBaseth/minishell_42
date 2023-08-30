/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:00:12 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/30 08:49:56 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/minishell.h"

void	execute_binary(t_data *data, char *arg)
{
	/*char	*full_path;
	char	**input;

	input = get_command(data->args->);
	full_path = ft_strdup(get_env(data, "PWD"));
	full_path = ft_strjoin(full_path, "/");
	full_path = ft_strjoin(full_path, arg);
	if (access(full_path, F_OK | X_OK) == 0)
	{
		execve(full_path, input, data->envp);
		perror("execve");
		panic(EXEC_ERR);
	}*/
	(void)data;
	(void)arg;
}

bool	check_if_binary(t_data *data, char *arg)
{
	char	*bin_name;
	int		i;
	
	(void)data;
	if (arg[0] == '.' && arg[1] == '/' && arg[2])
	{
		i = 1;
		while (arg[i] == '/')
			i++;
		bin_name = ft_strdup_range(arg, i, ft_strlen(arg));
		execute_binary(data, bin_name);
		return (true);
		// it's a binary!!!
	}
	return (false);
}
