#include "../cube.h"

int	null_rays(t_data *data)
{
	data->n = 0;
	while (data->n < data->max)
	{
		data->ray[data->n].init_tmp_angle = 0;
		data->ray[data->n].map_check_x = 0;
        data->ray[data->n].map_check_y = 0;
        data->ray[data->n].ray_len = 0;
        data->ray[data->n].ray_x = 0;
        data->ray[data->n].ray_y = 0;
        data->ray[data->n].tmp_x = 0;
        data->ray[data->n].tmp_y = 0;
		data->ray[data->n].tmp_angle = 0;
        data->ray[data->n].wall = '\0';
		data->n++;
	}
	return (1);
}

void	init_player(t_data *data)
{
	data->player.cell_x = (data->map.map_size / 2);
	data->player.cell_y = (data->map.map_size / 2);
	data->player.x = (data->player.map_x * data->map.map_size) + data->player.cell_x;
	data->player.y = (data->player.map_y * data->map.map_size) + data->player.cell_y;
}


int	init(t_data *data)
{
	data->max = 131;
	data->ray1 = data->max/2;
	data->xstart = 0;
	null_rays(data);
	init_map(data);
	init_player(data);
	init_rays(data);
	set_sprite(data);
	display_game(data);
	return (0);
}