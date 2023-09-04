/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:44:19 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/04 13:51:12 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
extern int	g_signal;

char	*signal_to_str(int nbr)
{
	int	nb;

	nb = nbr % 256;
	return (ft_itoa(nb));
}

void	init_vars(int *i, int *size, bool *quotes, bool *dquotes)
{
	*i = 0;
	*size = 0;
	*quotes = false;
	*dquotes = false;
}

static int		exit_status_size(void)
{
	char	*exit_status;
	int		size;

	exit_status = signal_to_str(g_signal);
	size = ft_strlen(exit_status);
	gc_free(exit_status);
	return (size);
}

static int	expand_size(char *input_at_i, int *i, t_data *data)
{
	int		var_size;
	char	*var_name;
	char	*var_value;

	*i += 1;
	if ((!input_at_i[1] || input_at_i[1] == ' ' || input_at_i[1] == '\"'))
		return (1);
	var_size = 0;
	while (input_at_i[var_size + 1] && input_at_i[var_size + 1] != ' '
		&& input_at_i[var_size + 1] != '\"'
		&& input_at_i[var_size + 1] != '\''
		&& input_at_i[var_size + 1] != '$')
		var_size += 1;
	if (var_size == 0)
		return (0);
	var_name = ft_substr(input_at_i, 1, var_size);
	var_value = get_env_value(data->lst_env, var_name);
	gc_free(var_name);
	*i += var_size;
	if (!var_value)
		return (0);
	return (ft_strlen(var_value));
}

int	get_new_length(t_data *data, char *input)
{
	int		i;
	int		size;
	bool	in_quotes;
	bool	in_dquotes;

	init_vars(&i, &size, &in_quotes, &in_dquotes);
	while (input[i])
	{
		if (input[i] == '\"' && !in_quotes)
			in_dquotes = !in_dquotes;
		if (input[i] == '\'' && !in_dquotes)
			in_quotes = !in_quotes;
		if ((input[i] == '$' && input[i + 1] == '?') && !in_quotes)
		{
			size += exit_status_size() - 1;
			i += 1;
		}
		else if (input[i] == '$' && !in_quotes)
			size += expand_size(&(input[i]), &i, data) - 1;
		else
			i += 1;
		size += 1;
	}
	return (size);
}
