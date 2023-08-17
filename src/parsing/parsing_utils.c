/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:32:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/17 13:24:25 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_input(void)
{
	char *raw_input;

	raw_input = readline("\033[32mminishell$\033[0m ");
	if (!raw_input)
		return (NULL);
	if (!check_brackets(raw_input))
	{
		printf("Not the same amount of brackets.\n");
		return (NULL);
	}
 	return (raw_input);
}

char	*ft_remove_last_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ')
		i--;
	str[i + 1] = 0;
	return (str);
}

char	*ft_remove_spaces(char *str)
{
	int	i;
	int	start;


	i = 0;
	while (str[i] == ' ')
		i++;
	start = i;
	while (str[i])
	{
		str[i - start] = str[i];
		i++;
	}
	str[i - start] = 0;
	str = ft_remove_last_spaces(str);
	return (str);
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
