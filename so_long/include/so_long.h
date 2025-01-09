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
	void	*img_ptr;
	char	*img_pixel;
	int	bpp;
	int	line_len;
	int	endian;
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

#endif
