/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:01:10 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/26 13:19:53 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	close_win(t_data *data)
{
	if (data->img.floor)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.player)
		mlx_destroy_image(data->mlx, data->img.player);
	if (data->img.exit)
		mlx_destroy_image(data->mlx, data->img.exit);
	if (data->img.collectible)
		mlx_destroy_image(data->mlx, data->img.collectible);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map.grid && !data->map.is_free)
		free_map(data->map.grid, data->map.height, data);
	exit(0);
}

void	free_map(char **grid, int height, t_data *data)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (i < height)
	{
		if (grid[i])
		{
			free(grid[i]);
			grid[i] = NULL;
		}
		i++;
	}
	free(grid);
	data->map.is_free = 1;
}

char	**copy_map(t_map *map, t_data *data)
{
	char	**temp;
	int		i;

	temp = malloc(sizeof(char *) * (map->height + 1));
	if (!temp)
	{
		return (NULL);
	}
	i = 0;
	while (i < map->height)
	{
		temp[i] = ft_strdup(map->grid[i]);
		if (!temp[i])
		{
			free_map(temp, i, data);
			return (NULL);
		}
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

void	flood_fill(char **temp, int y, int x, int *count)
{
	if (temp[y][x] == '1' || temp[y][x] == 'V')
		return ;
	if (temp[y][x] == 'C' || temp[y][x] == 'E')
		(*count)--;
	temp[y][x] = 'V';
	flood_fill(temp, y + 1, x, count);
	flood_fill(temp, y - 1, x, count);
	flood_fill(temp, y, x + 1, count);
	flood_fill(temp, y, x - 1, count);
}

char	*read_line(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
