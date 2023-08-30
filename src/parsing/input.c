/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:41:55 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/30 08:33:57 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//static char	validate_input(char *raw_input)
//{
//	Pass it throught the parser & lexer
//	That means : 	- get length of args
//					- get number of args
//					- get rid of whitespace (space or tabs)
//					- get operator and applies it.
//	GLHF :)
//}

// ne prend pas encore en compte si les parentheses sont dans des guillemets...

/*	checks if the character at index is inside quotes so we can ignore
	the meta-characters except $ */
bool 	is_inside_quotes(char *input, int index)
{
	char	first_quote;
	int		quotes;
	int		i;

	quotes = 0;
	first_quote = '\0';
	i = -1;
	while (++i <= index)
	{
		if (!first_quote && (input[i] == '\'' || input[i] == '"'))
		{
			first_quote = input[i];
			ft_printf("quote: %c\n", first_quote);
			if (i == index)
			{
				ft_printf("\nNOOB\n");
				return (false);
			}
		}
		if (first_quote == input[i])
		{
			quotes++;
			if (quotes % 2 == 0)
				first_quote = 0;
		}
	}
	ft_printf("  %d\n", quotes);
	if (quotes % 2 == 1)
		return (true);
	return (false);
}

/*	checks the amount of open '(' and closed ')' brackets so we can make the command fail*/
bool	check_brackets(char *raw_input)
{
	int	i;
	int	open_brackets;
	int	close_brackets;

	i = -1;
	open_brackets = 0;
	close_brackets = 0;
	while (raw_input[++i])
	{
		if (raw_input[i] == '(' && !is_inside_quotes(raw_input, i))
			open_brackets++;
		else if (raw_input[i] == ')' && !is_inside_quotes(raw_input, i))
			close_brackets++;
	}
	if (open_brackets != close_brackets)
		return (false);
	return (true);
}

/*	Returns the input of the user after validating it. */
/*
	Reproduire ce comportement ? :

	➜  minishell git:(parsing) ✗ ( (
	subsh subsh> (
	subsh subsh subsh> (
	subsh subsh subsh subsh> (
	subsh subsh subsh subsh subsh> "
	subsh subsh subsh subsh subsh dquote> 

	➜  minishell git:(parsing) ✗ (
	echo "coucou" 
	)  
	coucou
	➜  minishell git:(parsing) ✗ 

	Chaque ligne est un \n.
*/

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

char	**get_command(char *input)
{
	char **command;	
	char *separator = " ";
	char *parsed;
	int index = 0;

	command = gc_alloc(64 * sizeof(char *), "command");
	if (!command)
		panic(MALLOC_ERR);
	input = ft_remove_spaces(input);
	parsed = strtok(input, separator); // strtok not allowed!
	while (parsed != NULL)
	{
		command[index] = parsed;
		index++;
		parsed = strtok(NULL, separator);
	}
	command[index] = NULL;
	return (command);
}

