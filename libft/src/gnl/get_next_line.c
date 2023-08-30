/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:05:51 by acharlot          #+#    #+#             */
/*   Updated: 2023/08/30 09:28:12 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *stash, char *buf)
{
	char	*temp;

	temp = ft_strjoin(stash, buf);
	free(stash);
	return (temp);
}

char	*read_file(int fd, char *stash)
{
	char	*buf;
	int		rd;

	if (!stash)
		stash = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd] = 0;
		stash = ft_free(stash, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (stash);
}

char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line);
}

char	*ft_clear(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (stash[i])
		line[j++] = stash[i++];
	free(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, buff, 0) < 0)
		return (NULL);
	buff = read_file(fd, buff);
	line = ft_line(buff);
	buff = ft_clear(buff);
	return (line);
}
