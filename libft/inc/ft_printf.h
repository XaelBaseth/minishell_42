/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:29:29 by acharlot          #+#    #+#             */
/*   Updated: 2023/04/27 12:29:31 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printpercent(void);
int		ft_printf_hex(unsigned int num, const char format);
int		ft_printf_ptr(unsigned long long ptr);
int		ft_ptr_len(uintptr_t num);
int		ft_hex_len(unsigned int num);
int		ft_num_len(unsigned int num);
int		ft_printf_unsigned(unsigned int n);

char	*ft_uitoa(unsigned int n);

void	ft_putstr(char *str);
void	ft_put_ptr(uintptr_t num);
void	ft_put_hex(unsigned int num, const char format);

#endif
