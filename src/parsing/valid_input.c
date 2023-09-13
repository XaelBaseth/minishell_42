/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:17:48 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/13 09:14:58 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

/*	
	Prints out an error message if a character is unrecognized.
	@param char `token` : character that is not recognized.
	@returns `true` - always.
*/
bool	unexpected_token(char token)
{
	ft_putstr_fd(UNEXPECTED_TOKEN, STDERR_FILENO);
	ft_putchar_fd(token, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	return (true);
}

/*	
	Check if the operator (or combination of operator) is correct.
	@param `*input` : command entered by the user.
	@returns `true` or `false` - according to the result of the comparison.
*/
bool	invalid_operator(char *input)
{
	int		i;
	bool	in_quotes;

	in_quotes = false;
	i = -1;
	while (has_operator(&input[++i]))
	{
		if (is_char(QUOTES, input[i]))
			in_quotes = !in_quotes;
		if (is_char(OPERATOR, input[i] && !in_quotes))
		{
			if (input[i] == input[i + 1])
				i++;
			i++;
			if (input[i] == ' ')
			{
				while (input[++i] && input[++i] == ' ')
					if (is_char(OPERATOR, input[i]))
						return (unexpected_token(input[i]));
			}
			if (is_char(OPERATOR, input[i]))
				return (unexpected_token(input[i]));
		}
	}
	return (false);
}

/*	
	Continuation of the checking for the validation of the inputed string.
	@param `*input` : command entered by the user.
	@returns `true` or `false` - according to the result of the comparison.
*/
bool	invalid_syntax2(char *input)
{
	int		i;
	bool	in_quotes;

	i = 0;
	while (input[i])
	{
		if (is_char(QUOTES, input[i]))
			in_quotes = !in_quotes;
		if (((input[i] == '>' && input[i + 1] == '<')
				|| (input[i] == '<' && input[i + 1] == '>')
				|| (input[i] == '|' && input[i + 1] == '|')) && !in_quotes)
			return (unexpected_token(input[i + 1]));
		else if ((input[i] == '{' || input[i] == '}'
				|| input[i] == '(' || input[i] == ')'
				|| input[i] == '[' || input[i] == ']'
				||input[i] == ';' || input[i] == '&' || input[i] == '*')
			&& !in_quotes)
			return (unexpected_token(input[i]));
		i++;
	}
	return (false);
}

/*	
	Start of the checking for the validation of the inputed string. 
	@param `*input` : command entered by the user.
	@returns `true` or `false` - according to the result of the comparison.
*/
bool	invalid_syntax(char *input)
{
	if (input[0] == '|')
		return (unexpected_token('|'));
	if (input[ft_strlen(input) - 1] == '|')
	{
		ft_putendl_fd(PIPE_PROMPT, STDERR_FILENO);
		return (true);
	}
	if (is_char(REDIRECTS, input[ft_strlen(input) - 1]))
	{
		ft_putendl_fd(SYNTAXT_ERR, STDERR_FILENO);
		return (true);
	}
	return (false);
}

/*	Check if the input is valid or not.
	@param `*input` : command entered by the user.
	@returns `true` or `false` - according to the result of the comparison.
*/
bool	valid_input(char *input)
{
	bool	valid;

	valid = true;
	if (input == NULL)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	if (input[0] == '\0')
		valid = false;
	else if (unclosed_quote(input))
	{
		ft_putendl_fd("Uncloses quotes.", STDERR_FILENO);
		valid = false;
	}
	else if (invalid_syntax(input) || invalid_syntax2(input)
		|| invalid_operator(input))
	{
		valid = false;
	}
	if (!valid)
		gc_free(input);
	return (valid);
}
