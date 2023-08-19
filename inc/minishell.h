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
# include <limits.h>

/*	CONSTANT	*/
# define FAILURE -1
# define SUCCESS 0
# define MALLOC_ERR "Memory Allocation has failed."
# define PATH_ERR "PATH not found."
# define EXEC_ERR "An error occured while executing the program."

# define PATH_MAX 4096

/*	GLOBAL	*/
extern pid_t	g_pid;
extern int		g_status;


/*	STRUCTURES	*/
typedef struct s_env t_env;
typedef struct s_path t_path;

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

typedef struct	s_data
{
	char	*input;
	char	**args;
	int		argc;
	char	**envp;
	t_env	*lst_env;
	int		nb_env;
	char	*pwd;
	char	*path;
	char	*old_path;
	t_path	*arr_path;
	int		nb_path;
}			t_data;

/*	FUNCTIONS	*/

/*	SHELL	*/

//env_utils

char	**env_copy(t_data *data, char **envp);
void	re_store_env(t_data *data);

//env

void    store_env(char **envp, t_data *data);
t_env	*split_env(char *envp);
/*Prints the environment variables.*/
void	print_env(t_data *data);

//echo
/*Does the echo command*/
void	do_echo(t_data *data);

//pwd
void	set_pwd(t_data *data);
void	get_pwd(t_data *data);

//exit
/*Builtin: exits the current process and SHOULD return an exit status.*/
bool	do_exit(t_data *data);

//cd

void	do_cd(t_data *data);

//unset
/*Unsets the specified environment variables.
If they exist, they are removed.
If they don't, nothing happens.*/
void	do_unset(t_data *data);

//export

void	do_export(t_data *data);

/*	MAIN	*/
//utils

void	panic(char *str);
void	free_all(t_data *data);
bool	is_int(char *str);
char	*ft_strdup_range(const char *s, size_t from, size_t to);

//config_sig

void	sigint_handler(int signum);

/*	PARSING	*/
//input

bool 	is_inside_quotes(char *input, int index);
char	*get_input(void);
char	**get_command(char *input);
bool	line_is(t_data *data, char *content);
bool	line_starts_by(t_data *data, char *content);

//parsing_utils
char	*ft_remove_spaces(char *str);

//path

void	store_path(char *path, t_data *data);
void	print_path(t_data *data);
char	*get_path(t_data *data);

/*	BUILTINS	*/
//builtins

bool	builtins(t_data *data);

//exec

void	execute_cmd(t_data *data);

//process

void	create_processes(t_data *data);

#endif
