/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:00:57 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/13 08:06:02 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

/*	
	Returns the number of argument passed in the matrix given in the
	parameter. 
	@param `**parsed`: pointer toward an array of arguments passed as the user
	input.
	@returns `i` - numbers of arguments passed.
*/
int	get_argc(char **parsed)
{
	int	i;

	i = 0;
	while (parsed[i])
		i += 1;
	return (i);
}

/*	
	Return the number of arguments entered via the input.
	@param `*input`: command entered by the user.
	@returns `count` - numbers of argument in the  user input.
*/
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

/*	
	Free the linked list of arguments. 
	@param `**args`	: pointer to array of command entered by the user.
	@param `*data`	: linked list of enviromnent in which there are the
	arguments.
*/
void	clean_parsed(t_args *args, t_data *data)
{
	lst_clear(&args);
	args = NULL;
	data->args = NULL;
}

/*	
	Transform the input of the user into an array of command that can be
	understood by the minishell.
	@param `*input` : command entered by the user.
	@returns `parsed` - array of input that can be used by the environment.
*/
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

/*	Take the command of the user and return a trimed string while filling
	the args structure.
	@param `*input`: command entered by the user.
	@returns `head` - trimmed command.
*/
t_args	*parser(char *input)
{
	char	**parsed;
	t_args	*temp;
	t_args	*head;
	int		tracker[2];

	parsed = parse_input(input);
	gc_free(input);
	temp = new_lst(get_argc(&parsed[0]));
	head = temp;
	tracker[0] = 0;
	while (parsed[tracker[0]])
	{
		tracker[1] = 0;
		while (parsed[tracker[0]] && !is_char(OPERATOR, parsed[tracker[0]][0]))
			temp->argv[tracker[1]++] = remove_quote(parsed[tracker[0]++]);
		temp->argv[tracker[1]] = NULL;
		if (!parsed[tracker[0]])
			break ;
		temp->operator = get_operator(parsed[tracker[0]++]);
		temp->next = new_lst(get_argc(&parsed[tracker[1]]));
		temp = temp->next;
	}
	temp->next = NULL;
	gc_free(parsed);
	return (head);
}
