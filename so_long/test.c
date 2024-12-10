#include <stdlib.h>
#include "minilibx-linux/mlx.h"


typedef struct s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
    void	*mlx;
    void	*mlx_win;
    t_data	img;
    int		i;
    int		j;
    
    i = 0;
    j = 0;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World !");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (i <= 100)
    	my_mlx_pixel_put(&img, i++, j, create_trgb(255, 0, 0, 255));
    while (j <= 50)
    	my_mlx_pixel_put(&img, i, j++, 0x00FF0000);
    while (i != 0)
    	my_mlx_pixel_put(&img, i--, j, 0x00FF0000);
    while (j != 0)
    	my_mlx_pixel_put(&img, i, j--, 0x00FF0000);
mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
