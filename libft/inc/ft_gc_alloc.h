/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_alloc.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:46:10 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/13 08:52:31 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GC_ALLOC_H
# define FT_GC_ALLOC_H

/*	LIBRAIRY	*/

# include <stdlib.h>
# include "./ft_printf.h"

/*	STRUCTURE	*/

typedef struct s_alloc_ptr
{
	void				*addr;
	size_t				size;
	char				*name;
	struct s_alloc_ptr	*next;
}						t_alloc_ptr;

/*	FUNCTIONS	*/

t_alloc_ptr	*new_node(size_t size, char *name);
t_alloc_ptr	*remove_address(int index, t_alloc_ptr *lst);
t_alloc_ptr	*addr_save(t_alloc_ptr *ptr, int code);
void		lst_add_back(t_alloc_ptr *lst, t_alloc_ptr *new);
void		gc_free_all(void);
void		gc_free(void *addr);
void		*gc_alloc(size_t size, char *name);
void		print_address(void);

#endif