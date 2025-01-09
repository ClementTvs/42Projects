/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:15:08 by ctravers          #+#    #+#             */
/*   Updated: 2025/01/09 11:36:13 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


/*
Used by: key_press, close_cross
Use: Nothing

Destroy the window and the display then free the data and exit
*/
void	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_win(data);
	return (0);
}

/*
Used by: main
Use: Nothing

Close the window when the cross is clicked
*/
int	close_cross(t_data *data)
{
	close_win(data);
	return (0);
}

/*
Used by: count_map_height, load_map_lines
Use: Nothing

Initialize a line
Use GNL to get the line we want
Take the len of the line
If the last char is a \n we make it \0
-> We do this because the line don't need a \n, we just make it a string with \0
*/
char	*read_line(int fd)
{
	char	*line;
	int	len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

/*
Used by: init_map
Use: read_line

Initliaze the height
We read the map until the line is empty
Increment height for each loop
Free the line
*/
int	count_map_height(char *file)
{
	int	fd;
	char	*line;
	int	height;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	while (1)
	{
		line = read_line(fd);
		if (!line)
			break;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

/*
Used by: read_map
Use: count_map_height

Initialize the height
If the height is less than 3 then the map is only wall, return 0
Allocate the map grid with the height of the map to know how many line we need to fill
*/
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

/*
Used by: load_map_lines
Use: Nothing

If it's the first line (width == 0) then return the len of the first line
If not, compare the len of the actual line with the width (Which is set in load_map_lines)
*/
int	check_line_length(char *line, int width)
{
	if (!line)
		return (0);
	if (width == 0)
		return ((int)ft_strlen(line));
	return ((int)ft_strlen(line) == width );
}
/*
Used by: load_map_lines, main
Use: Nothing

Free the whole map
*/
void	free_map(char **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(grid[i++]);
	free(grid);
}

/*
Used by: read_map
Use: check_line_length, free_map, read_line

Initialize width to 0, then read the line we currently are in with 'i'
Check if the line length is valid, if not then free the map and return 0
If it's the first line, the width takes the length of it
When everything is done make the grid[i] NULL to avoid leak
*/
int	load_map_lines(t_data *data, int fd)
{
	int	i;

	i = 0;
	data->map.width = 0;
	while (i < data->map.height)
	{
		data->map.grid[i] = read_line(fd);
		if (!check_line_length(data->map.grid[i], data->map.width))
		{
			free_map(data->map.grid, i);
			close(fd);
			return (0);
		}
		if (i == 0)
			data->map.width = ft_strlen(data->map.grid[i]);
		i++;
	}
	data->map.grid[i] = NULL;
	return (1);
}
/*
Used by: main
Use: init_map, load_map_lines

Main function to check if the map is valid
*/
int	read_map(t_data *data, char *file)
{
	int	fd;

	if (!init_map(&data->map, file))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!load_map_lines(data, fd))
		return (0);
	close(fd);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*filename;

	if (argc != 2) 
	{
		ft_printf("Only take one argument which is a .ber file\n");
		return (1);
	}
	filename = ft_strrchr(argv[1], '.');
	if (!filename || ft_strncmp(filename, ".ber", 4) != 0)
	{
		ft_printf("File must be .ber\n");
		return (1);
	}
	if (!read_map(&data, argv[1]))
	{
		ft_printf("Invalid map format\n");
		return (1);
	}
	if (!validate_map(&data))
	{
		ft_printf("Invalid map content");
		free_map(data.map.grid, data.map.height);
		return (1);
	}
	find_player(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_printf("Failed to initialize MLX\n");
		return (1);
	}
	data.win = mlx_new_window(data.mlx, 1920, 1080, "so_long");
	if (!data.win)
	{
		ft_printf("Failed to create Window\n");
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (1);
	}
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_cross, &data);
	mlx_loop(data.mlx);
	return (0);
}
