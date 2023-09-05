/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:48:44 by axel              #+#    #+#             */
/*   Updated: 2023/09/05 09:35:21 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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

char	*trim(char *str1, char const *set)
{
	size_t	beg;
	size_t	end;
	char	*trimmed_str;

	if (!str1 || !set)
		return (NULL);
	beg = 0;
	while (str1[beg] != '\0' && ft_strchr(set, str1[beg]) != NULL)
		beg += 1;
	end = ft_strlen(str1 + beg);
	while (end > beg && ft_strchr(set, str1[(beg + end) - 1]) != NULL)
		end -= 1;
	trimmed_str = malloc((end + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	ft_strncpy(trimmed_str, (str1 + beg), end);
	free(str1);
	return (trimmed_str);
}
