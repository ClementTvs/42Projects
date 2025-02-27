/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:15:08 by ctravers          #+#    #+#             */
/*   Updated: 2025/02/26 13:27:47 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	has_collectibles(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	find_player(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x] == 'P')
			{
				data->pos.x = x;
				data->pos.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_all(t_data *data)
{
	data->img.collectible = NULL;
	data->img.exit = NULL;
	data->img.floor = NULL;
	data->img.wall = NULL;
	data->img.player = NULL;
	data->win = NULL;
	data->map.is_free = 0;
	data->map.grid = NULL;
	data->previous = '\0';
}

void	init_and_check(t_data *data, char **argv)
{
	init_all(data);
	if (!read_map(data, argv[1]))
	{
		ft_printf("Error: Invalid map format\n", 1);
		close_win(data);
	}
	find_player(data);
	if (!validate_map(data))
	{
		ft_printf("Error: Invalid map content\n", 1);
		close_win(data);
	}
	if (!load_textures(data))
	{
		ft_printf("Error: Failed to load textures\n", 1);
		close_win(data);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*filename;

	data.step_count = 0;
	if (argc != 2)
		return (ft_printf("Only take one argument which is a .ber file\n"), 1);
	filename = ft_strrchr(argv[1], '.');
	if (!filename || ft_strncmp(filename, ".ber", 4) != 0)
		return (ft_printf("File must be .ber\n"), 1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_printf("Failed to initialize MLX\n"), 1);
	init_and_check(&data, argv);
	data.win = mlx_new_window(data.mlx, data.map.width * 32,
			data.map.height * 32, "so_long");
	if (!data.win)
	{
		ft_printf("Error: Failed to create Window\n", 1);
		close_win(&data);
	}
	render_map(&data);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_cross, &data);
	mlx_loop(data.mlx);
}
