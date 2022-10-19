#include	"cube.h"

int		quarter_1(t_data *img, float pdx, float pdy)
{
	int len;

	len = 0;
	while (len < 20)
	{
		pdx = sin(img->angle) * len;
		pdy = cos(img->angle) * len;
		mlx_pixel_put(img->mlx, img->mlx_win, img->x + pdx, img->y - pdy, 0x00FF0000);
		len++;
	}
	img->pdx = pdx;
	img->pdy = pdy;
	return (0);
}

int		quarter_2(t_data *img, float pdx, float pdy)
{
	int len;

	len = 0;
	while (len < 20)
	{
		pdx = sin(img->angle) * len;
		pdy = cos(img->angle) * len;
		mlx_pixel_put(img->mlx, img->mlx_win, img->x + pdx, img->y + pdy, 0x00FF0000);
		len++;
	}
	img->pdx = pdx;
	img->pdy = pdy;
	return (0);
}

int		quarter_3(t_data *img, float pdx, float pdy)
{
	int len;

	len = 0;
	while (len < 20)
	{
		pdx = sin(img->angle) * len;
		pdy = cos(img->angle) * len;
		mlx_pixel_put(img->mlx, img->mlx_win, img->x - pdx, img->y + pdy, 0x00FF0000);
		len++;
	}
	img->pdx = pdx;
	img->pdy = pdy;
	return (0);
}

int		quarter_4(t_data *img, float pdx, float pdy)
{
	int len;

	len = 0;
	while (len < 20)
	{
		pdx = sin(img->angle) * len;
		pdy = cos(img->angle) * len;
		mlx_pixel_put(img->mlx, img->mlx_win, img->x - pdx, img->y - pdy, 0x00FF0000);
		len++;
	}
	img->pdx = pdx;
	img->pdy = pdy;
	return (0);
}