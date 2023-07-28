#ifndef MINISHELL_H
# define MINISHELL_H


# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define FAILURE -1
# define SUCCESS 0

void	panic(char *str);

#endif