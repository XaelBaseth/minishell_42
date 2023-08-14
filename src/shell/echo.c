/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:54:55 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/12 11:44:50 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// must add the fd for the redirections!
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

void	pass_spaces(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

void	do_echo(t_data *data)
{
	char	*n_str;
	int		i;
	int		new_start;
	bool	has_parameter;

	i = 4;
	n_str = data->input;
	has_parameter = false;
	pass_spaces(n_str, &i);
	new_start = i;
	check_parameter(n_str, &i, &new_start, &has_parameter);
	pass_spaces(n_str, &i);
	new_start = 0;
	while (n_str[i])
	{
		if (!(n_str[i] == ' ' && (n_str[i + 1] == ' ' || n_str[i + 1] == 0))
			&& (n_str[i] != '\'' && n_str[i] != '\"'))
			n_str[new_start++] = n_str[i];
		i++;
	}
	if (!has_parameter)
		n_str[new_start++] = '\n';
	n_str[new_start] = 0;
	ft_printf("%s", n_str);
}
