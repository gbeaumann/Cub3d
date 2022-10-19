#include	"cube.h"

int	rotation_left(t_data *img, float pdx, float pdy)
{
	int len;

	len = 0;
	img->angle += (PI/4);
	printf("angleeeee::::::: %f\n", img->angle);
	while (len < 20)
	{
		pdx = sin(img->angle) * len;
		pdy = cos(img->angle) * len;
		mlx_pixel_put(img->mlx, img->mlx_win, img->x + pdx, img->y + pdy, 0x00FF0000);
		len++;
	}
	return (0);
}

int	rotation_right(t_data *img, float pdx, float pdy)
{
	img->angle += (PI/4);
	if (img->quarter == 1)
		quarter_1(img, pdx, pdy);
	if (img->quarter == 2)
		quarter_2(img, pdx, pdy);
	if (img->quarter == 3)
		quarter_3(img, pdx, pdy);
	if (img->quarter == 4)
		quarter_4(img, pdx, pdy);
	
	return (0);
}

int	forward(t_data *img, float pdx, float pdy)
{
	int	len;
	float	newx;
	float	newy;
	printf("%f\n", img->angle);

	len = 0;
	newx = img->x + 5;
	newy = img->y + (5 * (tan(img->angle)));
	while (len < 20)
	{
		pdx = sin(img->angle) * len;
		pdy = cos(img->angle) * len;
		mlx_pixel_put(img->mlx, img->mlx_win, (newx + pdx), (newy + pdy), 0x00FF0000);
		len++;
	}
	return (0);
}