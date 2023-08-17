/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:17:48 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/17 11:17:12 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	unexpected_token(char token)
{
	ft_putstr_fd(UNEXPECTED_TOKEN, STDERR_FILENO);
	ft_putchar_fd(token, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	return (true);
}

bool	invalid_operator(char *input)
{
	int		i;
	bool	in_quotes;

	i = 0;
	in_quotes = false;
	while (has_operator(&input[i]))
	{
		if (is_inside_quotes(input, i))
			in_quotes = !in_quotes;
		if (is_char(OPERATOR, input[i]) && !in_quotes)
		{
			if (input[i] == input[i + 1])
				i += 2;
			else
				i += 1;
			if (input[i] == ' ')
			{
				ft_remove_spaces(input);
			}
			if (is_char(OPERATOR, input[i]))
				return (unexpected_token(input[i]));
		}
		i++;
	}
	return (false);
}

bool	invalid_syntax2(char *input)
{
	int		i;
	bool	in_quotes;

	i = 0;
	while(input[i])
	{
		if (is_inside_quotes(input, i))
			in_quotes = !in_quotes;
		if (((input[i] == '>' && input[i + 1] == '<')
			||(input[i] == '<' && input[i + 1] == '>')
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

bool	valid_input(char *input)
{
	bool	valid;

	valid = true;
	if (input == NULL)
	{
		free(input);
		panic("Enter arguments.");
	}
	if (input[0] == '\0')
		valid = false;
	else if (invalid_syntax(input) || invalid_syntax2(input)
		|| invalid_operator(input))
		valid = false;
	if (!valid)
		free(input);
	return (valid);
}