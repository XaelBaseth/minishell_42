/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:15:47 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/08 09:39:42 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Check if the inputed string contains an operator from the enum t_operator.
	@param char *input: string passed as a command from the user.
*/
bool	has_operator(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (is_char(OPERATOR, input[i]))
			return true;
		i += 1;
	}
	return (false);
}

/*	Returns the lenght of a token, wether it's a string, an operator or
	quoted character.
	@param char *input_at_i: pointer towards a character from a string inputed
		by the user.
*/
int	get_token_len(char *input_at_i)
{
	int		i;
	char	quotes;

	i = 0;
	if (is_char(OPERATOR, input_at_i[i]))
	{
		if (input_at_i[i] == input_at_i[i + 1])
			return (2);
		return (1);
	}
	while (input_at_i[i]
		&& !is_space(input_at_i[i])
		&& !is_char(OPERATOR, input_at_i[i]))
	{
		if (is_char(QUOTES, input_at_i[i]))
		{
			quotes = input_at_i[i++];
			while (input_at_i[i] && input_at_i[i] != quotes)
				i += 1;
		}
		i += 1;
	}
	return (i);
}

/*	Compare the character inputed to an operator and attribute the correct
	t_operator symbol.
	@param char *operator: string containing, or not, an operator.
*/
t_operator	get_operator(char *operator)
{
	t_operator	op;

	if (!operator)
		op = NONE;
	else if (streq(operator, "|"))
		op = PIPE;
	else if (streq(operator, ">>"))
		op = REDIR_OUTPUT_APPEND;
	else if (streq(operator, ">"))
		op = REDIR_OUTPUT_REPLACE;
	else if (streq(operator, "<<"))
		op = REDIR_INPUT_UNTIL;
	else if (streq(operator, "<"))
		op = REDIR_INPUT;
	else
		op = NONE;
	gc_free(operator);
	return (op);
}
