/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:38:49 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/30 09:32:56 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	Throw out an error message and exit the program. 
	char *str: Message to be printed.
*/
void	panic(char *str)
{
	gc_free_all();
	ft_printf("\033[31mError!\n%s\n\033[0m", str);
	exit(EXIT_FAILURE);
}

/*	Free the matrix used for the args linked list.
	char **matrix: pointer to a string array.
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

/*	Check if a string is equal to a character by comparing their ASCII number.
	const char *str: string to which we compare the ASCII number.
	int c: ASCII number of a character.
 */
bool	is_char(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

/*	Compare two string to see wether they are the same or not.
	char *str1: first string to compare.
	char *str2: second string to compare.
*/
bool	streq(char *str1, char *str2)
{
	int	i;

	if ((str1 && !str2) || (!str1 && str2))
		return (false);
	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (false);
		i += 1;
	}
	return (true);
}

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

bool	is_int(char *str)
{
	long long	big_number;

	if (!is_numeric(str))
		return (false);
	big_number = ft_atoll(str);
	if (big_number < INT_MIN || big_number > INT_MAX)
		return (false);
	return(true);
}

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