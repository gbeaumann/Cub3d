#include "../cube.h"

int	init_player(t_data *data)
{
	//int	y;

	//initialization of map
	init_map(data);

	//initialization of palyer
	data->player.cell_x = 30;
	data->player.cell_y = 30;
	data->player.x = (data->player.map_x * 60) + data->player.cell_x;
	data->player.y = (data->player.map_y * 60) + data->player.cell_y;
	//data->player.tmp_angle = 0;
	//data->player.pdx = 0;
	//data->player.pdy = 0;

	//initialization of rays
	data->max = 61;
	init_rays(data);

	int pdx;
	int pdy;

	pdx = 0;
	pdy = 0;
	display_ray(data, pdx, pdy);
	return (0);
}