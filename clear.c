
#include	"cube.h"

void	clear_quarter_1(t_data *img)
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
		mlx_pixel_put(img->mlx, img->mlx_win, img->x + pdx, img->y - pdy, 0);
		len++;
	}
}

void	clear_quarter_2(t_data *img)
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
		mlx_pixel_put(img->mlx, img->mlx_win, img->x + pdx, img->y + pdy, 0);
		len++;
	}
}

void	clear_quarter_3(t_data *img)
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
		mlx_pixel_put(img->mlx, img->mlx_win, img->x - pdx, img->y + pdy, 0);
		len++;
	}
}

void	clear_quarter_4(t_data *img)
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
		mlx_pixel_put(img->mlx, img->mlx_win, img->x - pdx, img->y - pdy, 0);
		len++;
	}
}

void	clear(t_data *img)
{
	printf("quarter: %d\n", img->quarter);
	if (img->quarter == 1)
		clear_quarter_1(img);
	if (img->quarter == 2)
		clear_quarter_2(img);
	if (img->quarter == 3)
		clear_quarter_3(img);
	if (img->quarter == 4)
		clear_quarter_4(img);
}