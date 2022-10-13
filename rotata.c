#include	"cube.h"

int	ft_clic_close(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit (0);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	init_player(t_data *img)
{
	int	y;

	img->x = 450;
	img->y = 300;
	img->angle = 0;
	img->pdx = 0;
	img->pdy = 0;
	img->quarter = 1;
	y = img->y;
	while (y > img->y - 20)
	{
		my_mlx_pixel_put(img, img->x, y, 0x00FF0000);
		y--;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

/*void	clear(t_data *img)
{
	int		len;
	float	pdx;
	float	pdy;

	len = 0;
	pdx = img->pdx;
	pdy = img->pdy;
	while (len < 20)
	{
		pdx = sin(img->angle) * len;
		pdy = cos(img->angle) * len;
		my_mlx_pixel_put(img, img->x + pdx, img->y + pdy, 0);
		len++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}*/

int	player_move(int keycode, t_data *img)
{
	float	pdx;
	float	pdy;
	
	clear(img);
	if (keycode == 123)
		rotation_left(img, pdx, pdy);
	if (keycode == 124)
		rotation_right(img, pdx, pdy);
	if (keycode == 13)
		forward(img, pdx, pdy);
	my_mlx_pixel_put(img, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	img;
	
	// initialisation mlx
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 900, 600, "Hello world!");
	img.img = mlx_new_image(img.mlx, 900, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	init_player(&img);
	mlx_hook(img.mlx_win, 2, 0, player_move, &img);
	mlx_hook(img.mlx_win, 17, 1L << 5, ft_clic_close, &img);
	mlx_loop(img.mlx);
}
	