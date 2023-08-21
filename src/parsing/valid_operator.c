/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:20:45 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/18 09:40:16 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Check the input between the quotes.
	char *input: command entered by the user.
	int index: count the character in the sequence.
*/
bool	check_in_quotes(char *input, int index)
{
	bool 	in_quotes;
	int		i;

	in_quotes = false;
	i = 0;
	while (i < index)
	{
		if (is_char(QUOTES, input[i]))
			in_quotes = !in_quotes;
		i++;
	}
	return in_quotes;
}

/*	Checks if the character sequence is valid or not.
	char *input: command entered by the user.
	int index: count the character in the sequence.
*/
bool	check_operator_sequence(char *input, int index)
{
	if (is_char(OPERATOR, input[index]) && !check_in_quotes(input, index))
	{
		if (input[index] == input[index + 1])
			return (input[index + 2] == ' ') || is_char(OPERATOR, input[index + 2]);
		else
			return (input[index + 1] == ' ') || is_char(OPERATOR, input[index + 1]);
	}
	return (false);
}