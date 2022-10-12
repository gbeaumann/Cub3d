#include	"./minilibix/mlx.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
#define		PI 3.1415926535	

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
	float	angle;
	float	pdx;
	float	pdy;
}				t_data;

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

void	clear(t_data *img)
{
	int	len;
	int	x;
	int	y;

	len = 0;
	x = img->pdx;
	y = img->pdy;
	while (len < 20)
	{
		my_mlx_pixel_put(img, x, y, 0);
		x--;
		y--;
		len++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

int	player_move(int keycode, t_data *img)
{
	float	pdx;
	float	pdy;
	int		len;
	
	len = 0;
	if (keycode == 124)
	{
		clear(img);
		printf("cououc\n");
		img->angle += (PI/4);
		while (len < 20)
		{
			pdx = sin(img->angle) * len;
			pdy = cos(img->angle) * len;
			my_mlx_pixel_put(img, img->x + pdx, img->y + pdy, 0x00FF0000);
			len++;
		}
		img->pdx = pdx;
		img->pdy = pdy;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	img;
	img.x = 450;
	img.y = 300;
	img.angle = 0;
	
	// initialisation mlx
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 900, 600, "Hello world!");
	img.img = mlx_new_image(img.mlx, 900, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_hook(img.mlx_win, 2, 0, player_move, &img);
	mlx_hook(img.mlx_win, 17, 1L << 5, ft_clic_close, &img);
	mlx_loop(img.mlx);
}
	