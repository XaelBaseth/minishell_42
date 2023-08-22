/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:16:52 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/22 16:57:13 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	change_pwd(t_data *data)
{
	(void)data;
}

void	update_old_pwd(t_data *data, char *old_pwd)
{
	ft_strlcpy(data->old_path, old_pwd, ft_strlen(old_pwd));
}

void	do_cd(t_data *data)
{
	(void)data;
	/*
		cd [directory]: Changes the current working directory to the specified directory.
			If no directory is provided, it changes to the user's home directory.
			Example:	cd /path/to/directory or simply cd to go to the home directory.
						cd Desktop goes to the child Desktop directory if it exists.
						If the directory doesn't exist, prints:
							bash: cd: Desktop: No such file or directory

		cd -: Switches between the current directory and the previous directory you were in.
			This is handy for toggling between two directories.
			Example: cd - switches back to the previous directory.

		cd ~ or cd ~username: Changes the current directory to the home directory of the currently
			logged-in user or the specified username.
			Example: cd ~john would go to the home directory of the user "john." (/home/cpothin)

		cd ..: Moves up one directory level (to the parent directory).
			Example: If you are in /home/user/documents, cd .. would take you to /home/user.
			Do nothing if already on the root directory.

		cd .: Stays in the current directory. This is mainly used to represent the current directory explicitly.
			Example: cd . does nothing and keeps you in the same directory. BUT the OLD_PWD is still exported

		cd /: Changes the current directory to the root directory.
			Example: cd / takes you to the root directory.

		
		OLD_PWD=/ exported at the start of the program. Sets it to the root directory.
		On directory change, export the current directory on the OLD_PWD, do the stuff,
		then export the new directory on the PWD.

		if it's absolute,
			if the folder exists
			update the path

		if it's relative, 
			join the current path to the argument (slash detection or in the parsing?)
			check if the folder exists 
	*/
	// char	temp[PATH_MAX];

	// getcwd(temp, PATH_MAX);
	// data->old_path = from;
	// if (data->args[1] == NULL || strncmp(data->args[1], "~", 1) == 0)
	// {
	// 	update_old_pwd(&temp[0], data);
	// 	chdir(getenv("HOME"));
	// 	change_pwd(data);
	// 	return ;
	// }
	// if (streq(data->args[1], "-"))
	// {
	// 	do_cd(data, data->old_path);
	// 	// cd to old pwd
	// 	return ;
	// }
	// if (chdir(data->args[1]) == SUCCESS)
	// {
	// 	update_old_pwd(&temp[0], data);
	// 	change_pwd(data);
	// }
}