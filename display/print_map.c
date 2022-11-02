#include	"../cube.h"

void	sprite(t_data *data, char type, int sprite_width, int sprite_height)
{
	if (type == '1')
		data->map.sprite = mlx_xpm_file_to_image(data->mlx.mlx,
			"./get_map_greg/asset/sprites/wall.xpm", &data->map.sprite_width, &data->map.sprite_height);
	if (type == '0')
		data->map.sprite = mlx_xpm_file_to_image(data->mlx.mlx,
			"./get_map_greg/asset/sprites/grid.xpm", &data->map.sprite_width, &data->map.sprite_height);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->map.sprite, sprite_width, sprite_height);
}

void	print_walls(t_data *data)
{
	int	sprite_width;
	int	sprite_height;
	int	map_width;
	int	map_height;

	data->map.small_map = 1;
	data->map.move_size = 5;
	data->map.map_size = 60;
	sprite_width = 0;
	sprite_height = 0;
	map_width = 0;
	map_height = 0;
	while (map_height < data->map.map_height)
	{
		while (map_width < data->map.map_width)
		{
			sprite(data, data->map.map[map_height][map_width], sprite_width, sprite_height);
			map_width++;
			sprite_width += 60;
		}
		sprite_width = 0;
		sprite_height += 60;
		map_width = 0;
		map_height++;
	}
}

void	sprite_small(t_data *data, char type, int sprite_width, int sprite_height)
{
	if (type == '1')
		data->map.sprite = mlx_xpm_file_to_image(data->mlx.mlx,
			"./get_map_greg/asset/sprites/wall_15.xpm", &data->map.sprite_width, &data->map.sprite_height);
	if (type == '0')
		data->map.sprite = mlx_xpm_file_to_image(data->mlx.mlx,
			"./get_map_greg/asset/sprites/grid_15.xpm", &data->map.sprite_width, &data->map.sprite_height);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->map.sprite, sprite_width, sprite_height);
}

void	print_mini_walls(t_data *data)
{
	int	sprite_width;
	int	sprite_height;
	int	map_width;
	int	map_height;

	data->map.small_map = 4;
	data->map.move_size = 2;
	data->map.map_size = 15;
	sprite_width = 0;
	sprite_height = 0;
	map_width = 0;
	map_height = 0;
	while (map_height < data->map.map_height)
	{
		while (map_width < data->map.map_width)
		{
			sprite_small(data, data->map.map[map_height][map_width], sprite_width, sprite_height);
			map_width++;
			sprite_width += 15;
		}
		sprite_width = 0;
		sprite_height += 15;
		map_width = 0;
		map_height++;
	}
}

void	print_game(t_data *data)
{
	int	wall_height;
	int len;
	int y;
	int y2;
	int x;

	len = 0;
	y = data->map.game_display_y / 2;
	y2 = data->map.game_display_y / 2;
	x = data->map.game_display_x / 2;
	printf("ray len: %d\n", data->ray.ray_len);
	wall_height = (data->ray.ray_len / (pow(data->ray.ray_len, 2))) * 1000;
	printf("wall: %d\n", wall_height);
	mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->map.game_display_x, data->map.game_display_y);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
	while (len < wall_height && len < 500)
	{
		my_mlx_pixel_put(data, x, y, 0x00FF0000);
		my_mlx_pixel_put(data, x, y2, 0x00FF0000);
		y--;
		y2++;
		len++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, data->map.game_display_start, 0);
}