/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:32:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/18 08:55:04 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Get the input entered as a command in the minishell. */
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
/*	Remove from the last space from a string.
	char *str: input from the user.
*/
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

/*	Deletes the extra space from a string. 
	char *str: input from the user.
*/
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

/*	Initialize the t_args linked list.
	int argc: number of argument in one command.
*/
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
/*	Clear the t_args linked list. 
	t_args **args: array of arguments entered by the user in a command.
*/
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
		gc_free(temp);
		temp = next_node;
	}
	*args = NULL;
}
