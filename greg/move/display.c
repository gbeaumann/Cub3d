#include "../cube.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		display_ray(t_data *img, float pdx, float pdy)
{
	int len;

	len = 0;
	while (len < 20)
	{
		pdx = sin(img->angle) * len;
		pdy = cos(img->angle) * len;
		my_mlx_pixel_put(img, img->x + pdx, img->y - pdy, 0x00FF0000);
		len++;
	}
	img->pdx = pdx;
	img->pdy = pdy;
	return (0);
}

void	clear(t_data *img)
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
		my_mlx_pixel_put(img, img->x + pdx, img->y - pdy, 0);
		len++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}