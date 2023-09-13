/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:42:37 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/13 09:01:20 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/expand.h"

extern int	g_signal;

/*
	Replace the expanded variable with the exit status of the last
	child process.
	@param `*expanded_input_at_i` : string reflecting the value of the
	exit status.
	@param `*i` : position tracker inside the `*expanded_input_at_i`.
	@returns `j` - numbers of characters added to `*expanded_input_at_i`.
*/
static int	expand_exit_status(char *expanded_input_at_i, int *i)
{
	char	*exit_status;
	int		j;

	*i += 2;
	exit_status = signal_to_str(g_signal);
	j = 0;
	while (exit_status[j])
	{
		expanded_input_at_i[j] = exit_status[j];
		j += 1;
	}
	gc_free(exit_status);
	return (j);
}

/*
	Replace the expanded variable with its true value from the environment.
	@param `*data`: environmnent of minishell.
	@param `*new_input`: string reflecting the value of the expanded variable.
	@param `*input`: command entered by the user.
	@param `*i`: position tracker inside the `input` string.
	@returns `j` - number of letters inside the `new input` variable.
*/
static int	expand_variable(t_data *data, char *new_input, char *input,
	int *i)
{
	char	*var_value;
	int		size;
	int		j;
	int		k;

	size = 0;
	j = 0;
	k = 0;
	*i += 1;
	if (!input[*i] || input[*i] == ' ' || input[*i] == '\"')
	{
		new_input[0] = '$';
		return (1);
	}
	while (input[*i + size] && input[*i + size] != ' '
		&& input[*i + size] != '\"' && !is_char(QUOTES, input[*i + size])
		&& input[*i + size] != '$')
		size += 1;
	var_value = get_env(data, ft_substr(input, *i, size));
	*i += size;
	if (!var_value)
		return (0);
	while (var_value[k])
		new_input[j++] = var_value[k++];
	return (j);
}

/*	
	Expands the variable defined by an `$` symbol, showing their value
	from the environment variable. With the exception of $? showing
	the exit code.
	@param `*data` : environment of the minishell.
	@param `*input` : arguments inputed by the user.
	@returns `expanded input` - value of the expanded variable.
*/
char	*expand(t_data *data, char *input)
{
	int		i;
	int		j;
	bool	in_quotes;
	bool	in_dquotes;
	char	*expanded_input;

	init_vars(&i, &j, &in_quotes, &in_dquotes);
	expanded_input = gc_alloc((get_new_length(data, input) + 1) * sizeof(char),
			"expanded_input");
	while (input[i])
	{
		if (input[i] == '\"' && !in_quotes)
			in_dquotes = !in_dquotes;
		if (input[i] == '\'' && !in_dquotes)
			in_quotes = !in_quotes;
		if (input[i] == '$' && input[i + 1] == '?' && !in_quotes)
			j += expand_exit_status(&(expanded_input[j]), &i);
		else if (input[i] && input[i] == '$' && !in_quotes)
			j += expand_variable(data, &(expanded_input[j]), input, &i);
		else
			expanded_input[j++] = input[i++];
	}
	expanded_input[j] = '\0';
	gc_free(input);
	return (expanded_input);
}
