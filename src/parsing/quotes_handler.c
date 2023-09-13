/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:41:55 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/13 09:07:23 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

/*	Checks if the character at index is inside quotes so we can ignore
	the meta-characters except $ 
	@param `*input`: command entered by the user.
	@param `index`: number of character in the input.
	@returns `true` or `false` - according to the result of the comparison.
*/
bool	is_inside_quotes(char *input, int index)
{
	int	quotes;
	int	double_quotes;
	int	i;

	quotes = 0;
	double_quotes = 0;
	i = -1;
	while (++i < index)
	{
		if (input[i] == '\'')
			quotes++;
		else if (input[i] == '\"')
			double_quotes++;
	}
	if (quotes % 2 == 1 || double_quotes % 2 == 1)
		return (true);
	return (false);
}

/*	
	Checks the amount of open '(' and closed ')' brackets so we can make the command
	fail.
	@param `*raw_input`: command entered by the user not trimed.
	@returns `true` or `false` - according to the result of the comparison.
*/
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

/*
	Check if the quotes are closed or not.
	@param `*str`: string to be checked.
	@returns `1` or `0` - according to the result of the comparison. 
*/
int	unclosed_quote(char *str)
{
	char	last_opened;

	last_opened = 0;
	while (*str && !last_opened)
	{
		if ((*str == '\'' || *str == '"'))
			last_opened = *str;
		str++;
	}
	while (*str && last_opened)
	{
		if (*str && *str == last_opened)
			last_opened = 0;
		str++;
	}
	if (*str)
		return (unclosed_quote(str));
	else if (!last_opened)
		return (0);
	else
		return (1);
}

/*	
	Return the size of a string ignoring quoted characters.
	@param `*parsed`: input by the user parsed.
	@returns `size` - size of the string ignoring quoted characters.
*/
int	remove_quote_size(char *parsed)
{
	int		i;
	int		size;
	char	quote;

	i = 0;
	size = 0;
	while (parsed[i])
	{
		while (parsed[i] && !is_char(QUOTES, parsed[i]))
		{
			i += 1;
			size += 1;
		}
		if (!parsed[i])
			break ;
		quote = parsed[i++];
		while (parsed[i] && parsed[i] != quote)
		{
			i += 1;
			size += 1;
		}
		quote = 0;
	}
	return (size);
}

/*	
	Returns a string with the quoted characters removed.
	@param *parsed: input by the user parsed.
	@returns `unquoted_parse` - string with the quoted characters removed.
*/
char	*remove_quote(char *parsed)
{
	int		i;
	int		j;
	char	quote;
	char	*unquoted_parsed;

	i = 0;
	j = 0;
	quote = '\0';
	unquoted_parsed = gc_alloc((remove_quote_size(parsed) + 1)
			* sizeof(char), "unquoted parsed");
	while (parsed[i])
	{
		while (parsed[i] && !is_char(QUOTES, parsed[i]))
			unquoted_parsed[j++] = parsed[i++];
		if (!parsed[i])
			break ;
		quote = parsed[i];
		i += 1;
		while (parsed[i] && parsed[i] != quote)
			unquoted_parsed[j++] = parsed[i++];
		quote = '\0';
	}
	unquoted_parsed[j] = '\0';
	gc_free(parsed);
	return (unquoted_parsed);
}
