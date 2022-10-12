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
}				t_data;

int	ft_clic_close(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit (0);
}

int	ft_close(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit(0);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	player_move(int	keycode, t_data *img)
{
	int	x;
	float px, py, pdx, pdy, pa;
	
	x = img->x;
	printf ("%d\n", keycode);
		while (x < img->x + 20)
		{
			my_mlx_pixel_put(img, img->y, x, 0);
			x++;
		}
	if (keycode == 123)
	{
		pa -= 0.1;
		if (pa < 0)
			pa += 2*PI;
		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
		my_mlx_pixel_put(img, pdy, pdx, 0x00FF0000);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	int len = 0;

	if (keycode == 124)
	{
		pa += 0.78;
		//if (pa > 2 * PI)
		//	pa -= 2*PI;
		//pdx = cos(pa) * 5;
		//pdy = sin(pa) * 5;
		while(len < 20)
		{
			pdx = sin(pa) * len;
			pdy = cos(pa) * len;
			my_mlx_pixel_put(img, pdx + img->x, pdy + img->y, 0x00FF0000);
			len++;
		}
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	if (keycode == 13)
	{
		img->x-=5;
		x = img->x;
		while (x < img->x + 20)
		{
			my_mlx_pixel_put(img, x, img->y, 0x00FF0000);
			x++;
		}
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	if (keycode == 0)
	{
		img->y-=5;
		x = img->x;
		while (x < img->x + 20)
		{
			my_mlx_pixel_put(img, x, img->y, 0x00FF0000);
			x++;
		}
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	if (keycode == 1)
	{
		img->x+=5;
		x = img->x;
		while (x < img->x + 20)
		{
			my_mlx_pixel_put(img, x, img->y, 0x00FF0000);
			x++;
		}
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	if (keycode == 2)
	{
		img->y+=5;
		x = img->x;
		while (x < img->x + 20)
		{
			my_mlx_pixel_put(img, x, img->y, 0x00FF0000);
			x++;
		}
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	/*if (keycode == 53)
	{
		mlx_hook(img->mlx_win, 2, 1L << 5, ft_close, &img);
		printf("salut\n");
	}*/
	return (0);
}

void print_player(t_data *img)
{
	int	x;

	x = img->x;
	while (x < img->x + 20)
	{
		my_mlx_pixel_put(img, x, img->y, 0x00FF0000);
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
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
	print_player(&img);
	//my_mlx_pixel_put(&img, img.y, img.x, 0x00FF0000);
	//mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 2, 0, player_move, &img);
	//mlx_hook(img.mlx_win, 2, 1L << 0, ft_close, &img);
	mlx_hook(img.mlx_win, 17, 1L << 5, ft_clic_close, &img);
	mlx_loop(img.mlx);
}