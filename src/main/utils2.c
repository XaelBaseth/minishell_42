/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:48:44 by axel              #+#    #+#             */
/*   Updated: 2023/09/12 14:40:14 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	
	Check if a string is equal to a character by comparing their ASCII number.
	@param `*str`: string to which we compare the ASCII number.
	@param `c`: ASCII number of a character.
	@returns `true` or `false` - according to the result of the comparison.
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

/*	
	Compare two string to see wether they are the same or not.
	@param `*str1`: first string to compare.
	@param `*str2`: second string to compare.
	@returns `true` or `false` - according to the result of the comparison.
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

/*	
	Returns a string without the character at the beginning or at the end
	of the command
	@param `*str1`: basic string to be trimmed.
	@param `*set`: set of character that are trimmed.
	@returns `trimmed_str` - Trimmes string without the character set.
*/
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
	trimmed_str = gc_alloc((end + 1) * sizeof(char), "trimmed string");
	if (!trimmed_str)
		return (NULL);
	ft_strncpy(trimmed_str, (str1 + beg), end);
	free(str1);
	return (trimmed_str);
}
