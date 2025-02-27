/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:05:08 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/26 13:20:17 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	validate_map(t_data *data)
{
	int	p_count;
	int	e_count;
	int	c_count;

	if (!check_walls(&data->map))
		return (0);
	if (!check_chars(&data->map))
		return (0);
	count_specials(&data->map, &p_count, &e_count, &c_count);
	if (p_count != 1 || e_count != 1 || c_count < 1)
		return (0);
	if (!check_path(data))
		return (0);
	return (1);
}

int	check_chars(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!ft_strchr("01CEP", map->grid[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_path(t_data *data)
{
	char	**temp;
	int		count;
	int		y;
	int		x;

	temp = copy_map(&data->map, data);
	if (!temp)
		return (0);
	count = 0;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (temp[y][x] == 'C' || temp[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	flood_fill(temp, data->pos.y, data->pos.x, &count);
	free_map(temp, data->map.height, data);
	data->map.is_free = 0;
	return (count == 0);
}

void	count_specials(t_map *map, int *p, int *e, int *c)
{
	int	x;
	int	y;

	y = 0;
	*p = 0;
	*e = 0;
	*c = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
				(*p)++;
			if (map->grid[y][x] == 'E')
				(*e)++;
			if (map->grid[y][x] == 'C')
				(*c)++;
			x++;
		}
		y++;
	}
}

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
