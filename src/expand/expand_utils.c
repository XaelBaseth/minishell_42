/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:44:19 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/13 09:01:53 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/expand.h"

extern int	g_signal;

/*
	Transform the signal sent to a string.
	@param `nbr`: signal sent.
	@returns `nb` : string that holds the signal value.
*/
char	*signal_to_str(int nbr)
{
	int	nb;

	nb = nbr % 256;
	return (ft_itoa(nb));
}

/*
	Initializes variable used in the `expand_variable` function.
	@param `*i`: position tracker.
	@param `*size`: size total of the expanded variable.
	@param `*quotes`: boolean checking if the input is between quotes.
	@param `*dquotes`: boolean checking if the inpute is between double quotes.
*/
void	init_vars(int *i, int *size, bool *quotes, bool *dquotes)
{
	*i = 0;
	*size = 0;
	*quotes = false;
	*dquotes = false;
}

/*
	Returns the size of the `exit_status` string.
	@returns `size` - size total of the `exit_status` string.
 */
static int	exit_status_size(void)
{
	char	*exit_status;
	int		size;

	exit_status = signal_to_str(g_signal);
	size = ft_strlen(exit_status);
	gc_free(exit_status);
	return (size);
}

/*
	Expand the size of a variable in a string.
	@param `*input_at_i`: expanded variable.
	@param `*i`: position tracker inside `*input_at_i`.
	@param `*data`: environment of minishell.
	@returns `lenght of var_value` - size total of the value of the variable.
*/
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
		&& !is_char(QUOTES, input_at_i[var_size + 1])
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

/*
	Performs every expansion needed on the variable and returns its size.
	@param `*data`: environmnent of the minishell.
	@param `*input`: command inputed by the user.
	@returns `size`: size total of the string after every expansion needed.
*/
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
		if ((input[i] == '$' && input[i + 1] == '?')
			&& !in_quotes)
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
