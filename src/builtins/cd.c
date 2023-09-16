/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:16:52 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/16 13:03:58 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtins.h"

/*
	This functions return the value of the environmment variable of minishell.
	@param `*data`: the environment of minishell.
	@param `*str`: the input of the user.
	@returns `lst->val` - the key and value of every variable of the 
	environment or `NULL` if not found.
*/
char	*get_env(t_data *data, char *str)
{
	t_env	*lst;

	lst = data->lst_env;
	while (lst)
	{
		if (ft_strcmp(lst->key, str) == 0)
			return (lst->val);
		lst = lst->next;
	}
	return (NULL);
}

/*
	Checks if a given directory exist and is a directory.
	@param `*data`: environmnent of the minishell.
	@param `*directory_path`: path to be checked.
	@returns `true` or `false` - Depending if the conditions is met or not.
*/
static bool	check_directory(t_data *data, const char *directory_path)
{
	struct stat	st;

	if (data->args->argc > 2)
	{
		ft_printf("minishell: cd: too many arguments\n");
		return (false);
	}
	if (stat(directory_path, &st) == 0)
	{
		if (S_ISDIR(st.st_mode))
			return (true);
		else
		{
			ft_printf("minishell: cd: %s: Not a directory\n",
				data->args->argv[1]);
			return (false);
		}
	}
	ft_printf("minishell: cd: %s: No such file or directory\n",
		data->args->argv[1]);
	return (false);
}

/*
	Change the current working directory and update the environmnent
	variables `PWD` and `OLDPWD`.
	@param `*data`: environment of the shell.
	@param `*new_path`: string of the new path to the current directory.
	@param `*old_path`: string of the old path from the current directory.
*/
static void	change_dir(t_data *data, const char *new_path, char *old_path)
{
	char		cur_path[PATH_MAX];

	chdir(new_path);
	export_var(data, ft_strjoin("OLDPWD=", old_path));
	getcwd(cur_path, PATH_MAX);
	export_var(data, ft_strjoin("PWD=", cur_path));
}

/*
	Check if there are argument following the command `cd`.
	@param `*data`: environmnent of the minishell.
	@param `arg`: string of argument acting as option for the input.
	@returns `arg_ok`- boolean variable that checks if the condition is
	met or not.
*/
static bool	check_argument(t_data *data, char *arg)
{
	bool	arg_ok;

	arg_ok = true;
	if (ft_strcmp(arg, "-") == 0)
	{
		change_dir(data, get_env(data, "OLDPWD"), get_env(data, "PWD"));
		ft_printf("%s\n", get_env(data, "PWD"));
	}
	else
		arg_ok = false;
	(void)data;
	return (arg_ok);
}

/*
	Change the current working directory and update the path.
	@param `*data`: environment of the minishell.
	@return `g_status` - int of the exit code of the command.
*/
int	do_cd(t_data *data)
{
	char		cur_path[PATH_MAX];
	const char	*directory_path;

	getcwd(cur_path, PATH_MAX);
	if (data->args->argc == 1 || ft_strcmp(data->args->argv[1], "~") == 0)
	{
		change_dir(data, getenv("HOME"), cur_path);
		return (set_g_status(SUCCESS));
	}
	if (check_argument(data, data->args->argv[1]) == true)
		return (set_g_status(ERROR));
	if (data->args->argv[1][0] == '/')
	{
		if (check_directory(data, data->args->argv[1]) == false)
			return (set_g_status(ERROR));
		change_dir(data, data->args->argv[1], cur_path);
		return (set_g_status(SUCCESS));
	}
	directory_path = ft_strjoin(cur_path, ft_strjoin("/", data->args->argv[1]));
	if (check_directory(data, directory_path) == false)
		return (set_g_status(ERROR));
	change_dir(data, directory_path, cur_path);
	return (set_g_status(SUCCESS));
}
