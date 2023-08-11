/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:54:55 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/11 10:50:26 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	do_echo(t_data *data) // must add the fd!
{
	char	*new_echo;
	int		i;
	int		new_start;
	char	quote_type;

	new_echo = data->input;
	if (!is_inside_quotes(data->input, ft_strlen(data->input) - 2))
		return ;
	i = 0;
	while (new_echo[i] != '\'' && new_echo[i] != '\"' && new_echo[i] != '\0')
		i++;
	if (new_echo[i] == '\'')
		quote_type = '\'';
	else
		quote_type = '\"';
	i++;
	new_start = 0;
	while (new_echo[i] != quote_type)
		new_echo[new_start++] = new_echo[i++];
	new_echo[new_start] = 0;
	ft_printf("%s\n", new_echo);
}
