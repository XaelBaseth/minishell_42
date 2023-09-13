/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:32:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/13 09:14:28 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

/*
	Actualise the numbers of arguments after the parsing.
	@param `*args`: command entered by the user.
*/
void	argc_post_parsing(t_args *args)
{
	t_args	*tmp;

	tmp = args;
	while (tmp->next)
	{
		tmp->argc -= tmp->next->argc;
		tmp = tmp->next;
	}
}

/*	
	Returns the input of the user after checking and trimming it.
	@returns `input` - command entered by the user.
*/
char	*get_input(void)
{
	char	*raw_input;
	char	*input;

	raw_input = readline("\033[32mminishell$\033[0m ");
	if (!raw_input)
		exit (EXIT_SUCCESS);
	if (!check_brackets(raw_input))
	{
		printf("Not the same amount of brackets.\n");
		exit (EXIT_FAILURE);
	}
	input = trim(raw_input, " \t");
	return (input);
}

/*	
	Check if the character c is a space or a formatting character.
	@param `c`: character that is checked.
	@returns `true` or `false` - according to the result of the comparison.
*/
bool	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

/*	
	Initialize the t_args linked list.
	@param `argc`: number of argument in one command.
	@returns `new_node` - created a new t_args point.
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

/*	
	Clear the t_args linked list. 
	@param `**args`: array of arguments entered by the user in a command.
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
