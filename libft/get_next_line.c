/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthaler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:10:40 by cthaler           #+#    #+#             */
/*   Updated: 2023/09/25 13:10:43 by cthaler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*store_rest(char *line, char *buf, int i, int j)
{
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (free(buf), NULL);
	i++;
	while (line[i + j])
	{
		buf[j] = line[i + j];
		j++;
	}
	return (buf[j] = 0, buf);
}

static char	*next_line(char *line, int i, int j)
{
	char	*temp;

	if (!line[0])
		return (free(line), NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	temp = ft_calloc(1, i + 1);
	if (!temp)
		return (free(line), NULL);
	while (line[j] && line[j] != '\n')
	{
		temp[j] = line[j];
		j++;
	}
	if (line[j] == '\n')
	{
		temp[j] = line[j];
		j++;
	}
	return (temp[j] = 0, free(line), temp);
}

static char	*save_space(int fd, char *line, int i_read, char *buf_read)
{
	int	i;

	while (i_read > 0)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
			i++;
		if (line[i] == '\n')
			break ;
		i_read = read(fd, buf_read, BUFFER_SIZE);
		if (i_read < 0)
			return (free(buf_read), free(line), NULL);
		buf_read[i_read] = 0;
		line = join_strings(line, buf_read);
		if (!line)
			return (free(line), free(buf_read), NULL);
	}
	return (line);
}

static char	*read_line(int fd, char *line, int i_read, char *buf)
{
	char	*buf_read;

	line = ft_strdup(buf);
	if (!line)
		return (0);
	buf_read = ft_calloc(1, BUFFER_SIZE + 1);
	if (!buf_read)
		return (0);
	line = save_space(fd, line, i_read, buf_read);
	if (!line)
		return (0);
	return (free(buf_read), line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
		buf = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!buf)
		return (0);
	line = read_line(fd, line, 1, buf);
	if (!line)
	{
		return (free(buf), buf = NULL, NULL);
	}
	buf = store_rest(line, buf, 0, 0);
	line = next_line(line, 0, 0);
	if (!line)
		return (free_buf(buf), buf = NULL, NULL);
	return (free(buf), line);
}
/*
#include<stdio.h>
#include <fcntl.h>
int main(void)
{
	int	fd;
	char	*s;
	
	fd = open("testfile.txt", 0);
	s = get_next_line(fd);
	while (s)
	{
		printf("LINE: %s\n", s);
		free(s);
		s = get_next_line(fd);
	}

	close(fd);
	return (0);
}
*/
