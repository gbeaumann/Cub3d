#include "cube.h"

int	init_player(t_data *img)
{
	int	y;

	img->x = 450;
	img->y = 330;
	img->cell_x = 30;
	img->cell_y = 30;
	img->map_x = 5;
	img->map_y = 5;
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