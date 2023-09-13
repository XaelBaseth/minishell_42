/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:38:49 by acharlot          #+#    #+#             */
/*   Updated: 2023/09/13 09:03:37 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	
	Throw out an error message and exit the program. 
	@param `*str`: Message to be printed.
	@returns `1` - exit code failure.
*/
void	panic(char *str)
{
	gc_free_all();
	ft_printf("\033[31mError!\n%s\n\033[0m", str);
	exit(EXIT_FAILURE);
}

/*	
	Free the matrix used for the args linked list.
	@param `**matrix`: pointer to a string array.
*/
void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		gc_free(matrix[i]);
		matrix[i] = NULL;
		i += 1;
	}
	gc_free(matrix);
	matrix = NULL;
}

/*
	Check if the string contains only numbers.
	@param `*str`: string to be checked.
	@returns `true` or `false` - according to wether the string
	contains only number or not.
*/
bool	is_numeric(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

/*
	Check if the string can be turned into an int.
	@param `*str`: string to be checked.
	@returns `true` or `false` - according to wether the string
	can be an int or not.
*/
bool	is_int(char *str)
{
	long long	big_number;

	if (!is_numeric(str))
		return (false);
	big_number = ft_atoll(str);
	if (big_number < INT_MIN || big_number > INT_MAX)
		return (false);
	return (true);
}

/*
	Creates a new string by copying specified characters.
	@param `*s`: string that will be copied.
	@param `from`: position tracker that start the copying.
	@param `to`: position tracker that end the copying.
	@returns `s_copy` - copy of the string with only the
	specified characters.
*/
char	*ft_strdup_range(const char *s, size_t from, size_t to)
{
	size_t	i;
	size_t	start;
	char	*s_copy;

	s_copy = (char *)gc_alloc((to - from + 1) * sizeof(char), "ft_strdup");
	if (!s_copy)
		return (NULL);
	i = 0;
	start = 0;
	while (s[i])
	{
		if (i >= from && i <= to)
			s_copy[start++] = s[i];
		i++;
	}
	s_copy[start] = '\0';
	return (s_copy);
}
