/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:37:29 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/15 11:59:01 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Get the PATH variable from the duplicated environment. */
char	*get_path(t_data *data)
{
	char	*path;
	int		i;
	
	path = NULL;
	i = 0;
	while (data->envp[i])
	{
		if (strncmp(data->envp[i], "PATH=", 5) == 0)
		{
			path = data->envp[i] + 5;
			break;
		}
		i++;
	}
	return (path);
}

/*	Split and store the PATH variables into the path structure. */
void	store_path(char *path, t_data *data)
{
	int i;
	int o;
	char **split_path;

	i = 0;
	data->path = path;
	if (!data->path)
		return ;
	split_path = ft_split(path, ':');
	while (split_path[i])
		i++;
	data->arr_path = (t_path *)gc_alloc(sizeof(t_path) * (i + 1),
		"path:path_array");
	if (!data->arr_path)
		return ;
	o = 0;
	while (o < i)
	{
		data->arr_path[o].path = ft_strdup(split_path[o]);
		o++;
	}
	data->nb_path = o;
	data->arr_path[o].path = NULL;
	gc_free(split_path);
}

/*	Print out the PATH variables /!\ MEM_LEAKS TO CHECK. */
void	print_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->arr_path[i].path)
	{
		ft_printf("The PATH variable is: %s\n",
			data->arr_path[i].path);
		i++;
	}
}
