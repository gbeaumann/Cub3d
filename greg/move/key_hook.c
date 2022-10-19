#include "../cube.h"

int	ft_clic_close(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit (0);
}

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
	if (keycode == 1)
		backward(img, pdx, pdy);
	check_cell(img);
	printf("quarter %d\n", img->quarter);
	cal_x_dist(img);
	//cal_y_dist(img);
	printf("\n");
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}