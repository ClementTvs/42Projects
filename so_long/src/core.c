/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:15:08 by ctravers          #+#    #+#             */
/*   Updated: 2025/01/07 11:38:44 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**read_map(const char *filename)
{
	int	fd;
	char	*line;
	char	**map;
	char	*tmp;

	fd = open(filename, 0_RDONLY)
	if (fd < 0)
		return (NULL);
	map = NULL;
	tmp = NULL;
	while ((line = get_next_line(fd)))
	{
		tmp = ft_strjoin(tmp, line);
		free(line);
	}
	map = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	return (map);
}

void	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_win(data);
	return (0);
}

int	close_cross(t_data *data)
{
	close_win(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Only take one argument which is a .ber file\n");
	}
	else
	{
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, 1920, 1080, "so_long");
		mlx_key_hook(data.win, key_press, &data);
		mlx_hook(data.win, 17, 0, close_cross, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
