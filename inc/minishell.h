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

/*	CONSTANT	*/
# define FAILURE -1
# define SUCCESS 0
# define MALLOC_ERR "Memory Allocation has failed."
# define PATH_ERR "PATH not found."

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
	t_path	*previous;
};

struct	s_env
{
	char	*key;
	char	*value;
	t_env	*previous;
	t_env	*next;
	bool	exported;
};

typedef struct	s_data
{
	char	*input;

	char	**envp;
	t_env	*arr_env;
	int		nb_env;
	
	char	*path;
	t_path	*arr_path;
	int		nb_path;
}			t_data;

/*	FUNCTIONS	*/

//shell/env.c

void    store_env(char **envp, t_data *data);
void	print_env(t_data *data);

//main/utils.c

void	panic(char *str);

//input.c

char	*get_input(void);
bool	line_is(t_data *data, char *content);

//main/config_sig.c

void	sigint_handler(int signum);

//builtins/builtins.c

bool	builtins(t_data *data);

//parsing/path.c

void 	store_path(char *path, t_data *data);
void	print_path(t_data *data);
char	*get_path(t_data *data);


#endif
