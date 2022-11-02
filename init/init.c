#include "../cube.h"

int	init_player(t_data *data)
{
	//int	y;

	//initialization of map
	data->map.map_height = data->map.map_size;
	data->map.map_width = data->map.map_size;
	data->map.game_display_x = 1280;
	data->map.game_display_y = 1024;
	data->map.game_display_start = 400;
	if (find_pos(data))
	{
		printf("Error in map\n");
		return (1);
	}

	int i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.map[j])
	{
		i = 0;
		while (data->map.map[j][i])
		{
			i++;
		}
		j++;
	}
	data->map.map_w = i - 1;
	data->map.map_h = j - 1;

	//initialization of palyer
	data->player.cell_x = 30 / data->map.small_map;
	data->player.cell_y = 30 / data->map.small_map;
	data->player.x = (data->player.map_x * (data->map.map_size)) + data->player.cell_x;
	data->player.y = (data->player.map_y * (data->map.map_size)) + data->player.cell_y;
	data->player.tmp_angle = 0;
	data->player.pdx = 0;
	data->player.pdy = 0;

	//initialization of ray
	data->ray.map_check_x = 0;
	data->ray.map_check_y = 0;
	data->ray.ray_x = 0;
	data->ray.ray_y = 0;
	data->ray.wall = '\0';

	int pdx;
	int pdy;
	display_ray(data, pdx, pdy);
	print_game(data);
	return (0);
}