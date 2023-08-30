/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:25:44 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/15 17:06:21 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	LIBRARY: N/A

	SYNOPSIS: 	Allocate memory and returns an array of strings by
				separating s with c, as a deliminator. The array
				must end by a NULL.
*/
#include "../../inc/libft.h"

int	count_words(const char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (*str)
	{
		if (*str != c && counter == 0)
		{
			counter = 1;
			i++;
		}
		else if (*str == c)
			counter = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = gc_alloc((finish - start +1) * sizeof(char), "word_dup");
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = gc_alloc((count_words(s, c) + 1) * sizeof(char *), "ft_split");
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
