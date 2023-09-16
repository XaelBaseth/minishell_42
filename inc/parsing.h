/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:07:50 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/16 13:19:06 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*	LIBRARY	*/

# include "minishell.h"
# include <stdbool.h>

/*	STRUCTURES	*/

typedef struct s_args	t_args;
typedef struct s_data	t_data;

typedef enum e_operator
{
	NONE,
	REDIR_OUTPUT_REPLACE,
	REDIR_OUTPUT_APPEND,
	REDIR_INPUT,
	REDIR_INPUT_UNTIL,
	PIPE,
}				t_operator;

struct s_args
{
	char		**argv;
	int			argc;
	t_operator	operator;
	t_args		*next;
};

/*	FUNCTIONS	*/

t_args		*parser(char *input);
t_args		*new_lst(int argc);
t_operator	get_operator(char *operator);
void		clean_parsed(t_args *args, t_data *data);
void		argc_post_parsing(t_args *args);
void		lst_clear(t_args **args);
bool		is_inside_quotes(char *input, int index);
int			unclosed_quote(char *str);
int			get_token_len(char *input_at_i);
char		*remove_quote(char *parsed);
char		*get_input(void);
bool		check_brackets(char *raw_input);
bool		valid_input(char *input);
bool		is_space(char c);
bool		has_operator(char *input);

#endif