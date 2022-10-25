#include "../cube.h"

int	ft_clic_close(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	exit (0);
}

int	player_move(int keycode, t_data *data)
{
	float	pdx;
	float	pdy;
	
	clear(data);

	if (keycode == 123)
		rotation_left(data, pdx, pdy);
	if (keycode == 124)
		rotation_right(data, pdx, pdy);
	if (keycode == 13)
		forward(data, pdx, pdy);
	if (keycode == 1)
		backward(data, pdx, pdy);
	check_cell(data);
	printf("quarter %d\n", data->player.quarter);
	cal_x_dist(data);
	//cal_y_dist(data);
	printf("\n");
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
	return (0);
}