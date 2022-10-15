#include	"../cube.h"

int	quarter_calculation(t_data *img)
{
	if ((img->angle >= 0) && (img->angle < PI/2))
		img->quarter = 1;
	if ((img->angle >= PI/2) && (img->angle < PI))
		img->quarter = 2;
	if ((img->angle >= PI) && (img->angle < (3 * PI)/2))
		img->quarter = 3;
	if ((img->angle >= (3 * PI)/2) && (img->angle < (2 * PI)))
		img->quarter = 4;
	return (0);
}

int	rotation_left(t_data *img, float pdx, float pdy)
{
	img->angle += ((2 * PI) - (PI/20));
	if (img->angle >= (2 * PI))
		img->angle -= (2 * PI);
	quarter_calculation(img);
	display_ray(img, pdx, pdy);
	return (0);
}

int	rotation_right(t_data *img, float pdx, float pdy)
{
	img->angle += (PI/20);
	if (img->angle >= (2 * PI))
		img->angle -= (2 * PI);
	quarter_calculation(img);
	display_ray(img, pdx, pdy);
	return (0);
}
