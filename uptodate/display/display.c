#include "../cube.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.line_length + x * (data->mlx.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_celling(t_data *data, int y)
{
	int	background_x;

	background_x = 0;
	while (background_x < data->map.game_display_x)
	{
		my_mlx_pixel_put(data, background_x, y, (((data->param.cr & 0xFF) << 16)  + ((data->param.cg & 0xFF) << 8) + (data->param.cb & 0xFF)));
		background_x++;
	}
}

void	print_floor(t_data *data, int y)
{
	int	background_x;

	background_x = 0;
	while (background_x < data->map.game_display_x)
	{
		my_mlx_pixel_put(data, background_x, y, (((data->param.fr & 0xFF) << 16)  + ((data->param.fg & 0xFF) << 8) + (data->param.fb & 0xFF)));
		background_x++;
	}
}

void	print_backgroud(t_data *data)
{
	int	horizon;
	int	y;

	horizon = data->map.game_display_y / 2;
	y = 0;
	while (y < horizon)
	{
		print_celling(data, y);
		y++;
	}
	while (y < data->map.game_display_y)
	{
		print_floor(data, y);
		y++;
	}
}

int	display_game(t_data *data)
{
	int len;

	len = 0;
	data->n = 0;
	mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->map.game_display_x, data->map.game_display_y);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
	print_backgroud(data);
	while (data->n < data->max)
	{
		find_ray_len(data);
		data->n++;
	}
	data->n = 0;
	while (data->n < data->max)
	{
		print_game(data);
		data->n++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, data->map.game_display_start, 0);
	return (0);
}

void	clear(t_data *data)
{
	int		len;
	float	pdx;
	float	pdy;

	len = 0;
	data->n = 0;
	while (data->n < data->max)
	{
		len = 0;
		pdx = data->ray[data->n].pdx;
		pdy = data->ray[data->n].pdy;
		while (len < data->ray[data->n].ray_len)
		{
			pdx = sin(data->ray[data->n].angle) * len;
			pdy = cos(data->ray[data->n].angle) * len;
			//mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, data->player.x + pdx, data->player.y - pdy, 0);
			len++;
		}
		data->n++;
	}
}