#include "mlx/mlx.h"
#include <stdlib.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data ->line_length + x * (data -> bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


void    colTracer(t_data *data, int x, int y)
{
    while(y < 1080)
	{
		my_mlx_pixel_put(data, x, y, 0x000000FF);
		y++;
	}
}


void	LineTracer(t_data *data, int y, int x)
{
	while(x < 1920)
    	{
        	my_mlx_pixel_put(data, x, y, 0x000000FF);
        	x++;
    	}
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
	int		pos = 0;


	img = (t_data *)malloc(sizeof(t_data));

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1921, 1081, "Hello world!");
	
	img->img = mlx_new_image(mlx, 1921, 1081);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	
	while(pos < 1921)
	{
		colTracer(img, pos, 0);
		pos += 40;
	}

	pos = 0;
	while(pos < 1081)
	{
		LineTracer(img, pos, 0);
		pos += 40;
	}

	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
}
