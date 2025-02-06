/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:22:16 by ctravers          #+#    #+#             */
/*   Updated: 2025/02/04 10:36:29 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img,
				x * data->img.width, y * data->img.height);
}

int	load_textures(t_data *data)
{
	data->img.width = 32;
	data->img.height = 32;

	data->img.wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
							&data->img.width, &data->img.height);
	data->img.floor= mlx_xpm_file_to_image(data->mlx, "textures/floor.xpm",
							&data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm",
							&data->img.width, &data->img.height);
	data->img.collectible = mlx_xpm_file_to_image(data->mlx, "textures/collectible.xpm",
							&data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm",
							 &data->img.width, &data->img.height);
	if (!data->img.wall || !data->img.floor || !data->img.player ||
		!data->img.collectible || !data->img.exit)
		return (0);
	return (1);
}

void	render_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (!data->map.grid[y]) // Vérifie si la ligne est NULL
            		{
                		ft_printf("Error: map.grid[%d] is NULL\n", y);
                		return;
            		}
           		ft_printf("Rendering at x=%d, y=%d, char=%c\n", x, y, data->map.grid[y][x]);
			put_image(data, data->img.floor, x, y);
			if (data->map.grid[y][x] == '1')
				put_image(data, data->img.wall, x, y);
			if (data->map.grid[y][x] == 'P')
				put_image(data, data->img.player, x, y);
			if (data->map.grid[y][x] == 'E')
				put_image(data, data->img.exit, x, y);
			if (data->map.grid[y][x] == 'C')
				put_image(data, data->img.collectible, x, y);
			x++;
		}
		y++;
	}
}
