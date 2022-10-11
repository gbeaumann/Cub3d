#include	"./minilibix/mlx.h"
#include	<stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	void	*mlx;
	void	*mlx_win;
}				t_data;

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	player_move(int	keycode, t_data *img)
{
	printf ("%d\n", keycode);
	my_mlx_pixel_put(img, img->y, img->x, 0);
	if (keycode == 13)
	{
		img->x-=5;
		my_mlx_pixel_put(img, img->y, img->x, 0x00FF0000);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
		if (keycode == 0)
	{
		img->y-=5;
		my_mlx_pixel_put(img, img->y, img->x, 0x00FF0000);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
		if (keycode == 1)
	{
		img->x+=5;
		my_mlx_pixel_put(img, img->y, img->x, 0x00FF0000);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
		if (keycode == 2)
	{
		img->y+=5;
		my_mlx_pixel_put(img, img->y, img->x, 0x00FF0000);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	return (0);
}

int	main(void)
{
	t_data	img;
	img.x = 450;
	img.y = 300;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 900, 600, "Hello world!");
	img.img = mlx_new_image(img.mlx, 900, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, img.y, img.x, 0x00FF0000);
	//mlx_loop_hook(img.mlx, player_move, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 2, 0, player_move, &img);
	//mlx_key_hook(img.mlx_win, player_move, &img);
	//printf("test\n");
	mlx_loop(img.mlx);
}