/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:05:56 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/30 09:26:54 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_clear(char *stash);
char	*ft_line(char *stash);
char	*read_file(int fd, char *stash);
char	*ft_free(char *stash, char *buf);
char	*ft_strjoin_bis(const char *s1, const char *s2);
char	*ft_strchr_bis(const char *string, int c);
char	*ft_calloc_bis(size_t elementCount, size_t elementSize);

void	ft_bzero_bis(void *s, size_t n);

size_t	ft_strlen_bis(char const *s);

#endif
