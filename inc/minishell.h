#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdbool.h>

# define FAILURE -1
# define SUCCESS 0

void	panic(char *str);

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
    t_env   *lst_env;
}               t_data;

void    store_env(char **envp, t_data *data);

#endif