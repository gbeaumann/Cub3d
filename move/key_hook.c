#include "../cube.h"

int	ft_clic_close(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	exit (0);
}

int	key_press(int keycode, t_data *data)
{
	
	if (keycode == 123)
		rotation_left(data);
	if (keycode == 124)
		rotation_right(data);
	if (keycode == 13)
		data->key.w = 1;
	if (keycode == 1)
		data->key.s = 1;
	if (keycode == 2)
		data->key.d = 1;
	if (keycode == 0)
		data->key.a = 1;
	if (keycode == 53)
		ft_clic_close(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	/*if (keycode == 123)
		data->key.left = 0;
	if (keycode == 124)
		data->key.right = 0;*/
	if (keycode == 13)
		data->key.w = 0;
	if (keycode == 1)
		data->key.s = 0;
	if (keycode == 2)
		data->key.d = 0;
	if (keycode == 0)
		data->key.a = 0;
	/*if (keycode == 53)
		ft_clic_close(data);*/
	return (0);
}

int	player_move(t_data *data)
{
	float	pdx;
	float	pdy;

	pdx = 0;
	pdy = 0;
	clear(data);
	data->n = 0;
	/*if (data->key.left == 1)
		data->key.left = 0;
	if (data->key.right == 1)
		data->key.right = 0);*/
	if (data->key.w == 1)
		forward(data);
	if (data->key.s == 1)
		backward(data);
	if (data->key.d == 1)
		right(data);
	if (data->key.a == 1)
		left(data);
	//if (keycode == 53)
	//	ft_clic_close(data);
	check_cell(data);
	display_game(data);
	//display_ray(data, pdx, pdy);
	return (0);
}