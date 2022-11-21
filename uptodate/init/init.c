#include "../cube.h"

int	null_rays(t_data *data)
{
	data->n = 0;
	while (data->n < data->max)
	{
		data->ray[data->n].map_check_x = 0;
        data->ray[data->n].map_check_y = 0;
        data->ray[data->n].map_x = 0;
        data->ray[data->n].map_y= 0;
        data->ray[data->n].ray_len = 0;
        data->ray[data->n].ray_x = 0;
        data->ray[data->n].ray_y = 0;
        data->ray[data->n].tmp_x = 0;
        data->ray[data->n].tmp_y = 0;
        data->ray[data->n].wall = '\0';
		data->n++;
	}
	return (1);
}

int	init_player(t_data *data)
{
	//int	y;

	data->max = 91;
	data->ray1 = data->max/2;
	null_rays(data);
	//initialization of map
	init_map(data);
	data->map.map_height = data->map.map_size;
	data->map.map_width = data->map.map_size;
	data->map.game_display_x = 1280;
	data->map.game_display_y = 1024;
	data->map.game_display_start = 400;
	//initialization of palyer
	data->player.cell_x = (data->map.map_size / 2);
	data->player.cell_y = (data->map.map_size / 2);
	data->player.x = (data->player.map_x * data->map.map_size) + data->player.cell_x;
	data->player.y = (data->player.map_y * data->map.map_size) + data->player.cell_y;
	//data->player.tmp_angle = 0;
	//data->player.pdx = 0;
	//data->player.pdy = 0;

	//initialization of rays
	init_rays(data);
	set_sprite(data);

	int pdx;
	int pdy;

	pdx = 0;
	pdy = 0;
	//display_ray(data, pdx, pdy);
	//print_game(data);
	display_game(data);
	return (0);
}