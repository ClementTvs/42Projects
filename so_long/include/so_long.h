/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:28:33 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/26 13:32:09 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/libft.h"
# include "../libft/include/get_next_line_bonus.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	int		width;
	int		height;
}		t_img;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		is_free;
}		t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_pos	pos;
	t_map	map;
	int		step_count;
	char	previous;
}		t_data;

void	close_win(t_data *data);
int		key_press(int keysym, t_data *data);
int		close_cross(t_data *data);
char	*read_line(int fd);
int		count_map_height(char *file);
int		init_map(t_map *map, char *file);
int		check_line_length(char *line, int width);
void	free_map(char **grid, int height, t_data *data);
int		load_map_lines(t_data *data, int fd);
int		read_map(t_data *data, char *file);
void	put_image(t_data *data, void *img, int x, int y);
int		load_textures(t_data *data);
void	render_map(t_data *data);
int		check_walls(t_map *map);
int		check_chars(t_map *map);
void	count_specials(t_map *map, int *p, int *e, int *c);
int		validate_map(t_data *data);
void	find_player(t_data *data);
int		has_collectibles(t_data *data);
void	flood_fill(char **temp, int y, int x, int *count);
char	**copy_map(t_map *map, t_data *data);
int		check_path(t_data *data);
void	init_all(t_data *data);
void	init_and_check(t_data *data, char **argv);
void	update_position(t_data *data, int new_y, int new_x);

#endif
