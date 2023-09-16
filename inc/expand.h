/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:24:20 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/16 13:18:50 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

/*	LIBRARY	*/

# include "minishell.h"
# include <stdbool.h>

/*	STRUCTURE	*/

typedef struct s_data	t_data;

/*	FUNCTIONS	*/

char		*expand(t_data *data, char *input);
char		*signal_to_str(int nbr);
void		init_vars(int *i, int *size, bool *quotes, bool *dquotes);
int			get_new_length(t_data *data, char *input);

#endif