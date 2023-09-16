/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:50:31 by cpothin           #+#    #+#             */
/*   Updated: 2023/09/16 13:06:35 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*	LIBRAIRY	*/

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_gc_alloc.h"
# include "parsing.h"
# include "builtins.h"
# include "expand.h"
# include "shell.h"

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
# define ERROR 1
# define SUCCESS 0
# define OPERATOR "|<>"
# define REDIRECTS "><"
# define QUOTES "\"\'"
# define PATH_MAX 4096

//ERROR MESSAGE
# define MALLOC_ERR "Memory Allocation has failed."
# define PATH_ERR "PATH not found."
# define EXEC_ERR "An error occured while executing the program."
# define PIPE_ERR "pipe() failed."
# define FORK_ERR "fork() failed."
# define SYNTAXT_ERR "Syntax error near unexpected token 'newline'."
# define HEREDOC_ERR " Syntax error: here-document delimited by end-of-file."
# define PIPE_PROMPT "No support for pipe prompt."
# define UNEXPECTED_TOKEN "Syntax error near unexpected token '"

/*	GLOBAL	*/

extern int				g_signal;

/*	STRUCTURES	*/

typedef struct s_env	t_env;
typedef struct s_path	t_path;
typedef struct s_args	t_args;

typedef struct s_data
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

/*	FUNCTIONS	*/

bool		is_char(const char *str, int c);
bool		streq(char *str1, char *str2);
bool		is_int(char *str);
char		*ft_strdup_range(const char *s, size_t from, size_t to);
char		*trim(char *str1, char const *set);
void		panic(char *str);
void		sigint_handler(int sig);
void		sigquit_handler(int sig);
void		setup_shell(char **envp, t_data *data);

#endif