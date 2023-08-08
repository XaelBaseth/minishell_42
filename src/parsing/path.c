/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:37:29 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/31 12:46:31 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
	ft_printf("path from get_path: %s\n", path);
	return (path);
	//getenv("PATH") on the dupe X
	//separate with each ":" X
	
	//allows a cycle search between the different path via a binary tree search
	//in order to return the correct commands
	
}
static t_path	split_path(char *path)
{
	t_path new_path;
	int i;
	int path_size;

	i = 0;
	if (!path)
		panic(PATH_ERR);
	while (path[i] != ':' && path[i] != '\0')
		i++;
	path_size = i;
	new_path.path = (char *)gc_alloc(sizeof(char) *
		(path_size + 1), "path: PATH var");
	if (new_path.path)
	{
		strncpy(new_path.path, path, path_size);
		new_path.path[path_size] = '\0';
	}
	return (new_path);
}

void	store_path(char **path, t_data *data)
{
	int i;
	int o;

	i = 0;
	data->path = path;
	if (!data->path)
		return ;
	ft_printf("path from store_path: %s\n", path);
	ft_printf("data->path[%d]: %s\n", i, data->path);
	while (data->path[i])
	{
		ft_printf("data->path[%d]: %p\n", i, (void*)data->path);
		i++;
	}
	data->nb_path = i;
	data->arr_path = (t_path *)gc_alloc(sizeof(t_path) * (i + 1),
		"path: path_array");
	if (!data->arr_path)
		return;
	o = 0;
	while (o < i)
	{
		data->arr_path[o] = split_path(path[o]);
		//ft_printf("%s\n", data->arr_path[o].path);
		o++;
	}
}


void	print_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->path[i])
	{
		ft_printf("%s\n", data->arr_path[i]);
		i++;
	}
}
