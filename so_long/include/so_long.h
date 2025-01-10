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


typedef struct	s_img
{
	void	*wall;
	char	*floor;
	int	*player;
	int	*collectible;
	int	*exit;
	int	width;
	int	height;
}		t_img;

typedef struct	s_map
{
	char	**grid;
	int	width;
	int	height;
}		t_map;

typedef struct	s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_pos	pos;
	t_map	map;
}		t_data;

void    close_win(t_data *data);
int     key_press(int keysym, t_data *data);
int     close_cross(t_data *data);
char    *read_line(int fd);
int     count_map_height(char *file);
int     init_map(t_map *map, char *file);
int     check_line_length(char *line, int width);
void    free_map(char **grid, int height);
int     load_map_lines(t_data *data, int fd);
int     read_map(t_data *data, char *file);
void    put_image(t_data *data, void *img, int x, int y);
int     load_textures(t_data *data);
void    render_map(t_data *data);
int	check_walls(t_map *map);
int	check_chars(t_map *map);
void	count_specials(t_map *map, int *p, int *e, int *c);
int	validate_map(t_data *data);
void	find_player(t_data *data);

#endif
