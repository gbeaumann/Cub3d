#include "../cube.h"

int	init_player(t_data *data)
{
	//int	y;

	//initialization of map
	data->map.map_height = 60;
	data->map.map_width = 60;
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
	data->player.cell_x = 30;
	data->player.cell_y = 30;
	data->player.x = (data->player.map_x * 60) + data->player.cell_x;
	data->player.y = (data->player.map_y * 60) + data->player.cell_y;
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
	return (0);
}