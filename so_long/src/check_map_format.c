/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:09:04 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/27 11:03:01 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_line(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

int	read_map(t_data *data, char *file)
{
	int		fd;
	char	*line;

	if (!init_map(&data->map, file))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!load_map_lines(data, fd))
	{
		line = get_next_line(fd);
		free_line(line, fd);
		return (close(fd), 0);
	}
	line = get_next_line(fd);
	free_line(line, fd);
	return (close(fd), 1);
}

int	load_map_lines(t_data *data, int fd)
{
	int	i;

	i = 0;
	data->map.width = 0;
	while (i < data->map.height)
	{
		data->map.grid[i] = read_line(fd);
		if (!data->map.grid[i])
		{
			free_map(data->map.grid, i, data);
			return (0);
		}
		if (data->map.grid[i][0] != '\0'
				&& !check_line_length(data->map.grid[i], data->map.width))
		{
			free_map(data->map.grid, i + 1, data);
			return (0);
		}
		if (i == 0)
			data->map.width = ft_strlen(data->map.grid[i]);
		i++;
	}
	data->map.grid[i] = NULL;
	return (1);
}

int	init_map(t_map *map, char *file)
{
	map->height = count_map_height(file);
	if (map->height < 3)
		return (0);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (0);
	return (1);
}

int	count_map_height(char *file)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	while (1)
	{
		line = read_line(fd);
		if (!line)
			break ;
		if (line[0] == '\0')
		{
			free_line(line, fd);
			break ;
		}
		height++;
		free(line);
	}
	close(fd);
	return (height);
}
