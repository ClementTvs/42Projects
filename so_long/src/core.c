/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:15:08 by ctravers          #+#    #+#             */
/*   Updated: 2025/02/06 11:19:38 by ctravers42       ###   ########.fr       */
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
	mlx_destroy_image(data->mlx, data->img.floor);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.player);
	mlx_destroy_image(data->mlx, data->img.exit);
	mlx_destroy_image(data->mlx, data->img.collectible);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map.grid, data->map.height);
	exit(0);
}

int	can_move(t_data *data, int new_y, int new_x)
{
	char	pos;

	if (new_y < 0 || new_y >= data->map.height)
		return (0);
	if (new_x < 0 || new_x >= data->map.width)
		return (0);
	pos = data->map.grid[new_y][new_x];
	if (pos == '1')
		return (0);
	return (1);
}

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

void	update_position(t_data *data, int new_y, int new_x)
{
	char	current;

	current = data->map.grid[new_y][new_x];
	if (current == 'E' && !has_collectibles(data))
	{
		ft_printf("You won !!\n");
		close_win(data);
	}
	data->step_count++;
	ft_printf("Steps: %d\n", data->step_count);
	if (current == 'C')
		data->previous = '0';
	else
		data->previous = data->map.grid[new_y][new_x];
	data->map.grid[data->pos.y][data->pos.x] = data->previous;
	data->map.grid[new_y][new_x] = 'P';
	data->pos.y = new_y;
	data->pos.x = new_x;
	render_map(data);
}

int	key_press(int keysym, t_data *data)
{
	int	new_y;
	int	new_x;
	
	new_y = data->pos.y;
	new_x = data->pos.x;
	if (keysym == XK_Escape)
		close_win(data);
	else if (keysym == XK_w)
		new_y--;
	else if (keysym == XK_s)
		new_y++;
	else if (keysym == XK_a)
		new_x--;
	else if (keysym == XK_d)
		new_x++;
	if (can_move(data, new_y, new_x) && (keysym == XK_w ||
				keysym == XK_d || keysym == XK_a || keysym == XK_s))
		update_position(data, new_y, new_x);
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
	char	*line;

	if (!init_map(&data->map, file))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!load_map_lines(data, fd))
		return (0);
	close(fd);
	line = get_next_line(fd);
	if (line)
		free(line);
	return (1);
}

/*
Used by: validate_map
Use: Nothing

Check if the map has wall all around it
*/
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

/*
Used by: validate_map
Use: Nothing

Check if there is chars that are not supposed to be there
*/
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

/*
Used by: validate_map
Use: Nothing

Count how many P, C and E are on the map
*/
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

/*
Used by: main
Use: check_walls, check_chars, count_specials

Check for any error in the map content
*/
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

void flood_fill(char **temp, int y, int x, int *count)
{
	if (temp[y][x] == '1' || temp[y][x] == 'V')
		return;
	if (temp[y][x] == 'C' || temp[y][x] == 'E')
		(*count)--;
	temp[y][x] = 'V';
	flood_fill(temp, y + 1, x, count);
	flood_fill(temp, y - 1, x, count);
	flood_fill(temp, y, x + 1, count);
	flood_fill(temp, y, x - 1, count);
}

char	**copy_map(t_map *map)
{
	char	**temp;
	int	i;

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
			free_map(temp, i);
			return (NULL);
		}
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

int	check_path(t_data *data)
{
	char	**temp;
	int	count;
	int	y;
	int	x;

	temp = copy_map(&data->map);
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
	free_map(temp, data->map.height);
	return (count == 0);
}

/*
Used by: main
Use: Nothing

Find the char P in the map and assign the position to the player
*/
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
				return;
			}
			x++;
		}
		y++;
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
	if (!read_map(&data, argv[1]))
		return (ft_printf("Invalid map format\n"), 1);
	find_player(&data);
	if (!validate_map(&data))
		return (ft_printf("Invalid map content\n"), 
				free_map(data.map.grid, data.map.height), 1);
	if (!load_textures(&data))
		return (ft_printf("Failed to load texture\n"), 1);
	data.win = mlx_new_window(data.mlx, data.map.width * 32, 
			data.map.height * 32, "so_long");
	if (!data.win)
		return (ft_printf("Failed to create Window\n"), 
			mlx_destroy_display(data.mlx), free(data.mlx), 1);
	render_map(&data);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_cross, &data);
	mlx_loop(data.mlx);
}
