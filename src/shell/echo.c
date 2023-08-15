/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:54:55 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/15 11:59:01 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	must add the fd for the redirections!
*/
void	check_parameter(char *str, int *i, int *new_start, bool *has_parameter)
{
	while (true)
	{
		if (str[*new_start] == '-' && str[*new_start + 1] == 'n')
		{
			*new_start += 2;
			while (str[*new_start] == 'n')
				(*new_start)++;
			if (str[*new_start] == ' ')
			{
				*i = (*new_start)++;
				*has_parameter = true;
			}
			else
			{
				*new_start = *i;
				break ;
			}
		}
		else
			break ;
	}
}

void	skip_spaces(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

bool	is_next_space(char *str, int i)
{
	if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == 0))
		return (true);
	return (false);
}

void	re_echo(char *str, int i, bool has_parameter)
{
	int		quote_position;
	char	quote_type;
	int		new_start;

	new_start = 0;
	quote_type = 0;
	while (str[i])
	{
		if (quote_type == 0 && (str[i] == '\'' || str[i] == '"'))
		{
			quote_type = str[i];
			quote_position = i;
		}
		if (str[i] != quote_type)
		{
			if (!(is_next_space(str, i) && quote_type == 0))
				str[new_start++] = str[i];
		}
		else if (quote_position != i)
			quote_type = '\0';
		i++;
	}
	if (!has_parameter)
		str[new_start++] = '\n';
	str[new_start] = 0;
}

void	do_echo(t_data *data)
{
	char	*str;
	int		i;
	int		new_start;
	bool	has_parameter;

	i = 4;
	str = data->input;
	has_parameter = false;
	skip_spaces(str, &i);
	new_start = i;
	check_parameter(str, &i, &new_start, &has_parameter);
	skip_spaces(str, &i);
	new_start = 0;
	re_echo(str, i, has_parameter);
	ft_printf("%s", str);
}
