/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:32:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/08/17 08:15:48 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_input(void)
{
	char *raw_input;

	raw_input = readline("\033[32mminishell$\033[0m ");
	if (!raw_input)
		return (NULL);
	if (!check_brackets(raw_input))
	{
		printf("Not the same amount of brackets.\n");
		return (NULL);
	}
 	return (raw_input);
}

char	*ft_remove_last_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ')
		i--;
	str[i + 1] = 0;
	return (str);
}

char	*ft_remove_spaces(char *str)
{
	int	i;
	int	start;


	i = 0;
	while (str[i] == ' ')
		i++;
	start = i;
	while (str[i])
	{
		str[i - start] = str[i];
		i++;
	}
	str[i - start] = 0;
	str = ft_remove_last_spaces(str);
	return (str);
}

bool	line_is(t_data *data, char *content)
{
	if (ft_strncmp(data->input, content, ft_strlen(content) + 1) == 0)
		return (true);
	return (false);
}

bool	line_starts_by(t_data *data, char *content)
{
	int	n;
	int	i;

	n = 0;
	while (content[n])
		n++;
	i = 0;
	while (i < n)
	{
		if (data->input[i] != content[i])
			return (false);
		i++;
	}
	return (true);
}
