/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:46:02 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/16 13:29:15 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*	LIBRARY	*/
# include "minishell.h"
# include <stdbool.h>

/*	STRUCTURES	*/
typedef struct s_env	t_env;
typedef struct s_path	t_path;
typedef struct s_args	t_args;
typedef struct s_data	t_data;

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

/*	FUNCTIONS	*/

t_env		*split_env(char *envp);
char		**env_copy(t_data *data, char **envp);
char		*get_short_var(char *arg);
char		*new_env_val(t_env *env, char *arg);
char		*get_env(t_data *data, char *str);
char		*get_env_value(t_env *lst, char *var_name);
void		store_env(char **envp, t_data *data);
void		re_store_env(t_data *data);
void		free_lst_node(t_env *node);
void		export_var(t_data *data, char *arg);
int			print_env(t_data *data);
int			do_echo(t_data *data);
int			get_pwd(t_data *data);
int			do_exit(t_data *data);
int			do_cd(t_data *data);
int			single_export(t_data *data);
int			do_unset(t_data *data);
int			do_export(t_data *data);

#endif