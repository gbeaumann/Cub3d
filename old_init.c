#include "../cube.h"

int	init_player(t_data *data)
{
	int	y;

	//initialization of map
	data->map.map_height = 60 / data->map.small_map;
	data->map.map_width = 60 / data->map.small_map;
	//map gnl greg
	//data->map.map = open_map("map1");


	//initialization of palyer
	data->player.cell_x = 30 / data->map.small_map;
	data->player.cell_y = 30 / data->map.small_map;
	data->player.map_x = 7;
	data->player.map_y = 5;
		//data->map = open_map("map1");
	data->player.x = (data->player.map_x * 60 / data->map.small_map) + data->player.cell_x;
	data->player.y = (data->player.map_y * 60 / data->map.small_map) + data->player.cell_y;
	data->player.angle = 0;
	data->player.tmp_angle = 0;
	data->player.pdx = 0;
	data->player.pdy = 0;
	data->player.quarter = 1;

	//initialization of ray
	data->ray.map_check_x = 0;
	data->ray.map_check_y = 0;
	data->ray.ray_len = 0;
	data->ray.ray_x = 0;
	data->ray.ray_y = 0;

	//display function (may be replace by a universal one)
	y = data->player.y;
	while (y > data->player.y - 20 / data->map.small_map)
	{
		//my_mlx_pixel_put(data, data->player.x, y, 0x00FF0000);
		mlx_pixel_put(data->mlx.mlx,data->mlx.mlx_win, data->player.x, y, 0x00FF0000);
		y--;
	}
	//mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
	return (0);
}