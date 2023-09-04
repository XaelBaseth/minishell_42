/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:32:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/04 14:50:00 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Returns the input of the user after validating it. */
char	*get_input(void)
{
	char	*raw_input;

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

/*	Check if the character c is a space or a formatting character.
	char c: character that is checked.
*/
bool	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
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
