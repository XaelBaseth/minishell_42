#ifndef MINISHELL_H
# define MINISHELL_H

/*	LIBRAIRY	*/
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdbool.h>

/*	CONSTANT	*/
# define FAILURE -1
# define SUCCESS 0

/*	STRUCTURES	*/

typedef struct s_env t_env;

struct  s_env
{
    char    *key;
    char    *value;
    t_env   *previous;
    t_env   *next;
    bool     exported;
};

typedef struct  s_data
{
    char    **envp;
    t_env   *arr_env;
    int     nb_env;
}               t_data;


/*	FUNCTIONS	*/

//env.c

void    store_env(char **envp, t_data *data);
//utils.c

void	panic(char *str);
//input.c

char	*get_input(void);

#endif