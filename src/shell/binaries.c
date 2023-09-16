/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:00:12 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/16 13:03:11 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shell.h"

/*	
	Execute the binary file found in the path.
	@param *data: environment of the minishell.
	@param *arg: the name of the binary file.
	@param *prefix: characters that prefixes the binare file.
*/
void	execute_binary(t_data *data, char *arg, char *prefix)
{
	char	*full_path;

	if (prefix)
		full_path = ft_strdup(prefix);
	else
		full_path = ft_strdup(get_env(data, "PWD"));
	full_path = ft_strjoin(full_path, "/");
	full_path = ft_strjoin(full_path, arg);
	if (access(full_path, F_OK | X_OK) == 0)
	{
		execve(full_path, data->args->argv, data->envp);
		perror("execve");
		panic(EXEC_ERR);
	}
	(void)data;
	(void)arg;
}

/*
	Checks if the command is a binary and tries to execute it.
	@param `*arg` : the argument to check.
	@returns `true` if the binary exists and starts with no error,
	`false` if not.
*/
bool	check_if_binary(t_data *data, char *arg)
{
	char	*bin_name;
	int		i;

	if (arg[0] == '/' && arg[1])
	{
		execute_binary(data, arg, "/");
		return (true);
	}
	else if (arg[0] == '.' && arg[1] == '/' && arg[2])
	{
		i = 1;
		bin_name = ft_strdup_range(arg, i, ft_strlen(arg));
		execute_binary(data, bin_name, get_env(data, "PWD"));
		return (true);
	}
	else if (arg[0] != '/' && arg[1])
	{
		bin_name = ft_strjoin(ft_strjoin(get_env(data, "PWD"), "/"), arg);
		if (!bin_name || access(bin_name, F_OK | X_OK) != 0)
			return (false);
		execute_binary(data, arg, get_env(data, "PWD"));
		return (true);
	}
	return (false);
}
