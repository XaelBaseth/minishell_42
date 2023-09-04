/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:50:31 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/04 11:03:47 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*	LIBRAIRY	*/
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_gc_alloc.h"
# include "parser.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

/*	CONSTANT	*/
# define FAILURE -1
# define SUCCESS 0
# define OPERATOR "|<>"
# define REDIRECTS "><"
# define QUOTES "\"\'"

//ERROR MESSAGE
# define MALLOC_ERR "Memory Allocation has failed."
# define PATH_ERR "PATH not found."
# define EXEC_ERR "An error occured while executing the program."

# define PATH_MAX 4096
# define PIPE_PROMPT "No support for pipe prompt."
# define SYNTAXT_ERR "Syntax error near unexpected token 'newline'."
# define UNEXPECTED_TOKEN "Syntax error near unexpected token '"
# define PIPE_ERR "pipe() failed."
# define FORK_ERR "fork() failed."

/*	STRUCTURES	*/
typedef struct s_env t_env;
typedef struct s_path t_path;
typedef struct s_args t_args;
typedef struct s_signal t_signal;

typedef enum	e_operator
{
	NONE,
	REDIR_OUTPUT_REPLACE,
	REDIR_OUTPUT_APPEND,
	REDIR_INPUT,
	REDIR_INPUT_UNTIL,
	PIPE,
}				t_operator;

struct s_path
{
	char	*path;
	t_path	*next;
};

struct	s_env
{
	char	*key;
	char	*val;
	t_env	*previous;
	t_env	*next;
	bool	has_value;
};

struct s_args
{
	char		**argv;
	int			argc;
	t_operator operator;
	t_args		*next;
};

typedef struct	s_data
{
	char	**envp;
	t_env	*lst_env;
	int		nb_env;
	char	*path;
	char	*old_path;
	t_path	*arr_path;
	int		nb_path;
	t_args	*args;
}			t_data;

struct s_signal
{
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
};

/*	GLOBAL	*/
extern t_signal	g_signal;

/*	FUNCTIONS	*/

/*	SHELL	*/

//env_utils

char		**env_copy(t_data *data, char **envp);
void		re_store_env(t_data *data);
char		*get_short_var(char *arg);

//env_utils2

char		*new_env_val(t_env *env, char *arg);
void		free_lst_node(t_env *node);
char		*get_env_value(t_env *lst, char *var_name);

//export_single
/*Prints the environment variables by ascii order.*/
void		single_export(t_data *data);

//env

/*	Duplicates and stores the environment variables through a 'key
	and value' variable setup in the t_env structure. */
void    	store_env(char **envp, t_data *data);
/*Splits a char * into a t_env node (node->key, node->val).*/
t_env		*split_env(char *envp);
/*Prints the environment variables.*/
void		print_env(t_data *data);

//echo
/*Does the echo command*/
void		do_echo(t_data *data);

//pwd
void		set_pwd(t_data *data);
void		get_pwd(t_data *data);

//exit
/*Builtin: exits the current process and SHOULD return an exit status.*/
bool		do_exit(t_data *data);

//cd

void		do_cd(t_data *data);
/*Takes the `env name` and returns its value.*/
char		*get_env(t_data *data, char *str);

//unset
/*Unsets the specified environment variables.
If they exist, they are removed.
If they don't, nothing happens.*/
void		do_unset(t_data *data);

//export

void		do_export(t_data *data);
void		export_var(t_data *data, char *arg);

/*	MAIN	*/
//utils

void		panic(char *str);
bool		is_char(const char *str, int c);
bool		streq(char *str1, char *str2);
bool		is_int(char *str);
char		*ft_strdup_range(const char *s, size_t from, size_t to);

//config_sig

void		sigint_handler(int sig);
void		sigquit_handler(int sig);

//init

void		setup_shell(char **envp, t_data *data, t_args **args);

/*	PARSING	*/
//parser

t_args		*parser(char *input);
void		clean_parsed(t_args **args, t_data *data);

//quotes_handler

bool 		is_inside_quotes(char *input, int index);
int			unclosed_quote(char *str);
char		*remove_quote(char *parsed);

//parsing_utils

char		*ft_remove_spaces(char *str);
bool		check_brackets(char *raw_input);
t_args		*new_lst(int argc);
void		lst_clear(t_args **args);
char		*get_input(void);

//operator

bool		has_operator(char *input);
int			get_token_len(char *input_at_i);
t_operator	get_operator(char *operator);

//valid_input

bool		valid_input(char *input);

/*	BUILTINS	*/
//path

void		store_path(char *path, t_data *data);
void		print_path(t_data *data);
char		*get_path(t_data *data);

//builtins

bool		builtins(t_args *input, t_data *data);

//exec

void		execute_cmd(t_args *input, t_data *data);

//process

void		create_processes(t_args *input, t_data *data);

//redirect

void		exec_redirect(t_args *input, t_data *data);

//pipe

void		exec_pipe(t_args *input, t_data *data);

//binaries
bool		check_if_binary(t_data *data, char *arg);

// EXPAND

//expand
char		*expand(t_data *data, char *input);

//expand_utils
char		*signal_to_str(int nbr);
void		init_vars(int *i, int *size, bool *quotes, bool *dquotes);
int			get_new_length(t_data *data, char *input);


#endif
