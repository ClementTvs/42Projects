/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:11:32 by ctravers          #+#    #+#             */
/*   Updated: 2025/01/09 10:04:43 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

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
	line = malloc((ft_strlen_gnl(buffer) - i + 1) * sizeof(char));
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
		if (!res || ft_strchr_gnl(buffer, '\n'))
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
	static char	*buf[4096];
	char		*line;
	ssize_t		readb;

	readb = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = readfile(fd, buf[fd], readb);
	if (!buf[fd])
		return (NULL);
	line = goodline(buf[fd]);
	if (!line)
	{
		free(buf[fd]);
		buf[fd] = NULL;
		return (NULL);
	}
	buf[fd] = deldoneline(buf[fd]);
	return (line);
}
