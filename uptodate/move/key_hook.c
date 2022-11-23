#include "../cube.h"

int	ft_clic_close(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	exit (0);
}

int	player_move(int keycode, t_data *data)
{
	clear(data);
	data->n = 0;
	if (keycode == 123)
		rotation_left(data);
	if (keycode == 124)
		rotation_right(data);
	if (keycode == 13)
		forward(data);
	if (keycode == 1)
		backward(data);
	if (keycode == 2)
		right(data);
	if (keycode == 0)
		left(data);
	check_cell(data);
	display_game(data);
	return (0);
}