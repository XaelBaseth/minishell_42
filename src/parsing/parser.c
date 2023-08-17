/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:00:57 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/17 11:11:18 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	get_argc(char **parsed)
{
	int	i;

	i = 0;
	while (parsed[i])
		i += 1;
	return (i);
}

int	get_nb_input(char *input)
{
	int		count;
	bool	flag;
	bool	quote;

	count = 0;
	flag = false;
	quote = false;
	while (*input)
	{
		if (is_char(OPERATOR, *input))
			count += 1;
		if (is_char(QUOTES, *input) && *input == *(input + 1))
			input += 1;
		else if (is_char(QUOTES, *input))
			quote = !quote;
		if (*input != ' ' && !is_char(OPERATOR, *input) && !flag && !quote)
		{
			flag = true;
			count += 1;
		}
		else if (*input == ' ' || is_char(OPERATOR, *input))
			flag = false;
		input += 1;
	}
	return (count);
}

void	clean_parsed(t_args **args, t_data *data)
{
	lst_clear(args);
	*args = NULL;
	data->args = NULL;
}

char	**parse_input(char *input)
{
	int		i;
	int		k;
	char	**parsed;
	int		len;
	int		j;

	i = 0;
	k = 0;
	parsed = gc_alloc((get_nb_input(input) + 1) * sizeof(char *), "parsed");
	while (input[i])
	{
		len = get_token_len(&input[i]);
		if (!len)
		{
			i += 1;
			continue ;
		}
		parsed[k] = gc_alloc((len + 1) * sizeof(char), "parsed[k]");
		j = 0;
		while (input[i] && j < len)
			parsed[k][j++] = input[i++];
		parsed[k++][j] = '\0';
	}
	parsed[k] = NULL;
	return (parsed);
}

t_args	*parser(char *input)
{
	char	**parsed;
	t_args	*temp;
	t_args	*head;
	int		idx[2];

	parsed = parse_input(input);
	free(input);
	temp = new_lst(get_argc(&parsed[0]));
	head = temp;
	idx[0] = 0;
	while (parsed[idx[0]])
	{
		idx[1] = 0;
		while (parsed[idx[0]] && !is_char(OPERATOR, parsed[idx[0]][0]))
			temp->argv[idx[1]++] = remove_quote(parsed[idx[0]++]);
		temp->argv[idx[1]] = NULL;
		if (!parsed[idx[0]])
			break ;
		temp->operator = get_operator(parsed[idx[0]++]);
		temp->next = new_lst(get_argc(&parsed[idx[1]]));
		temp = temp->next;
	}
	temp->next = NULL;
	free(parsed);
	return (head);
}