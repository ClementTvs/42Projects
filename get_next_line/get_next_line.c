/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:21:53 by ctravers          #+#    #+#             */
/*   Updated: 2024/12/05 11:20:00 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*deldoneline(char *buffer)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

void	*free_memory(char *buffer, char *res)
{
	free(buffer);
	free(res);
	return (NULL);
}

char	*readfile(int fd, char *res, ssize_t readb)
{
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!res)
	{
		res = malloc(1);
		if (!res)
			return (free_memory(buffer, NULL));
		res[0] = '\0';
	}
	readb = 1;
	while (readb > 0)
	{
		readb = read(fd, buffer, BUFFER_SIZE);
		if (readb == -1)
			return (free_memory(buffer, res));
		buffer[readb] = '\0';
		res = ft_free(res, buffer);
		if (!res || ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*goodline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	ssize_t		readb;

	readb = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = readfile(fd, buf, readb);
	if (!buf)
		return (NULL);
	line = goodline(buf);
	if (!line && buf)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	buf = deldoneline(buf);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	//int		fd2;
	//int		fd3;
	fd1 = open("tests/test1.txt", O_RDONLY);
	//fd2 = open("tests/test2.txt", O_RDONLY);
	//fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		//printf("line [%02d]: %s", i, line);
		free(line);
		//line = get_next_line(fd2);
		//printf("line [%02d]: %s", i, line);
		//free(line);
		//line = get_next_line(fd3);
		//printf("line [%02d]: %s", i, line);
		//free(line);
		i++;
	}
	close(fd1);
	//close(fd2);
	//close(fd3);
	return (0);
}
