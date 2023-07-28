/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:41:55 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/28 17:29:08 by cpothin          ###   ########.fr       */
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
bool check_brackets(char *raw_input)
{
	int	i;
	int	open_brackets;
	int	close_brackets;

	i = -1;
	open_brackets = 0;
	close_brackets = 0;
	while (raw_input[++i])
	{
		if (raw_input[i] == '(')
			open_brackets++;
		else if (raw_input[i] == ')')
			close_brackets++;
	}
	if (open_brackets == close_brackets)
		return (true);
	return (false);
}

/*	Returns the input of the user after validating it. */
char	*get_input(void)
{
	char *raw_input;
	//char *input;

	raw_input = readline("\033[32mminishell$\033[0m ");
	//input = validate_input(raw_input);
	//penser a changer le return en input
 	return (raw_input);
}
