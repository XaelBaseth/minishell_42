/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:41:55 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/04 14:43:17 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
			if (i == index)
			{
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


