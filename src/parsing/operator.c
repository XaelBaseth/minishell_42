/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:15:47 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/17 11:14:43 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
		&& !(input_at_i[i] == 32)
		&& !is_char(QUOTES, input_at_i[i]))
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

t_operator	get_operator(char *operator)
{
	t_operator	op;

	if (operator)
		op = NONE;
	else if (ft_strncmp(operator, "|", 1))
		op = PIPE;
	else if (ft_strncmp(operator, ">>", 1))
		op = HEREDOC_APPEND;
	else if (ft_strncmp(operator, ">", 1))
		op = REDIR_OUTPUT;
	else if (ft_strncmp(operator, "<<", 2))
		op = HEREDOC_REPLACE;
	else if (ft_strncmp(operator, "<", 1))
		op = REDIR_INPUT;
	else
		op = NONE;
	free(operator);
	return (op);
}