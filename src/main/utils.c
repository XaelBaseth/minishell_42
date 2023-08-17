/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:38:49 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/17 10:58:29 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Throw out an error message and exit the program. */
void	panic(char *str)
{
	gc_free_all();
	ft_printf("\033[31mError!\n%s\n\033[0m", str);
	exit(EXIT_FAILURE);
}

void	free_matrix(char **matrix)
{
	int	i;
	
	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		gc_free(matrix[i]);
		matrix[i] = NULL;
		i += 1;
	}
	gc_free(matrix);
	matrix = NULL;
}

void	lst_clear(t_args **args)
{
	t_args	*temp;
	t_args	*next_node;

	if (!args)
		return ;
	temp = *args;
	while (temp != NULL)
	{
		next_node = temp->next;
		free(temp);
		temp = next_node;
	}
	*args = NULL;
}

bool	is_char(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

t_args	*new_lst(int argc)
{
	t_args	*new_node;

	new_node = gc_alloc(sizeof(t_args), "t_args : new_node");
	new_node->argc = argc;
	new_node->argv = gc_alloc((argc + 1) * sizeof(char *), "t_args: argv");
	new_node->operator = NONE;
	new_node->next = NULL;
	return (new_node);
}