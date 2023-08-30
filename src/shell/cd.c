/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:16:52 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/23 15:19:43 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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

static bool	check_directory(t_data *data, const char *directory_path)
{
	struct stat	st;

	if (data->argc > 2)
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
			ft_printf("minishell: cd: %s: Not a directory\n", data->args[1]);
			return (false);
		}
	}
	ft_printf("minishell: cd: %s: No such file or directory\n", data->args[1]);
	return (false);
}

static void	change_dir(t_data *data, const char *new_path, char *old_path)
{
	char		cur_path[PATH_MAX];

	chdir(new_path);
	export_var(data, ft_strjoin("OLDPWD=", old_path));
	getcwd(cur_path, PATH_MAX);
	export_var(data, ft_strjoin("PWD=", cur_path));
}

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

/* `cd ""` ne doit rien faire, avec le parsing qui passe les "" */
void	do_cd(t_data *data)
{
	char		cur_path[PATH_MAX];
	const char	*directory_path;

	getcwd(cur_path, PATH_MAX);
	if (data->argc == 1 || ft_strcmp(data->args[1], "~") == 0)
	{
		change_dir(data, getenv("HOME"), cur_path);
		return ;
	}
	if (check_argument(data, data->args[1]) == true)
		return ;
	if (data->args[1][0] == '/')
	{
		if (check_directory(data, data->args[1]) == false)
			return ;
		change_dir(data, data->args[1], cur_path);
		return ;
	}
	directory_path = ft_strjoin(cur_path, ft_strjoin("/", data->args[1]));
	if (check_directory(data, directory_path) == false)
		return ;
	change_dir(data, directory_path, cur_path);
}
