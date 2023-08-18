#ifndef MINISHELL_H
# define MINISHELL_H

/*	LIBRAIRY	*/
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_gc_alloc.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdbool.h>
# include <signal.h>
# include "parser.h"

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
# define PIPE_PROMPT "No support for pipe prompt."
# define SYNTAXT_ERR "Syntax error near unexpected token 'newline'."
# define UNEXPECTED_TOKEN "Syntax error near unexpected token '"


/*	GLOBAL	*/
extern pid_t	g_pid;
extern int		g_status;


/*	STRUCTURES	*/

typedef struct s_env t_env;
typedef struct s_path t_path;
typedef struct s_args t_args;

typedef enum	e_operator
{
	NONE,
	REDIR_OUTPUT,
	REDIR_INPUT,
	HEREDOC_APPEND,
	HEREDOC_REPLACE,
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
	bool	exported;
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
	t_env	*arr_env;
	int		nb_env;
	char	*pwd;
	char	*path;
	t_path	*arr_path;
	int		nb_path;
	t_args	*args;
}			t_data;

/*	FUNCTIONS	*/

/*	SHELL	*/
//env

void    	store_env(char **envp, t_data *data);
void		print_env(t_data *data);

//echo
void		do_echo(t_data *data);

//pwd
void		set_pwd(t_data *data);
void		get_pwd(t_data *data);

/*	MAIN	*/
//utils

void		panic(char *str);
bool		is_char(const char *str, int c);
bool		streq(char *str1, char *str2);

//config_sig

void		sigint_handler(int signum);

//init

void	setup_shell(char **envp, t_data *data, t_args **args);

/*	PARSING	*/
//parser

t_args		*parser(char *input);
void		clean_parsed(t_args **args, t_data *data);

//quotes_handler

bool 		is_inside_quotes(char *input, int index);

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

//valid_operator

bool		check_operator_sequence(char *input, int index);
bool		check_in_quotes(char *input, int index);

/*	BUILTINS	*/
//path

void		store_path(char *path, t_data *data);
void		print_path(t_data *data);
char		*get_path(t_data *data);

//builtins

bool	builtins(t_args *input, t_data *data);

//exec

void		execute_cmd(t_args *input, t_data *data);

//process

void		create_processes(t_args *input, t_data *data);

//redirect

void		exec_redirect(t_args *input);

#endif
