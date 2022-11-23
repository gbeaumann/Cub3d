#include "../cube.h"

int quarter_one_yaxis(t_data *data)
{
	long double y;

	y = data->map.map_size * (data->player.map_y - 1);
	data->ray[data->n].tmp_x = data->player.x + (data->player.cell_y *(tan(data->ray[data->n].angle)));
	data->ray[data->n].map_check_x = data->ray[data->n].tmp_x / data->map.map_size;
	data->ray[data->n].map_check_y = y / data->map.map_size;
	return (0);
}

int quarter_two_yaxis(t_data *data)
{
	long double tmp_y;
	long double y;

	tmp_y = data->map.map_size - data->player.cell_y;
	y = data->map.map_size * (data->player.map_y + 1);
	data->ray[data->n].tmp_x = data->player.x + (tmp_y /(tan (data->ray[data->n].tmp_angle)));
	data->ray[data->n].map_check_x = (data->ray[data->n].tmp_x / data->map.map_size);
	data->ray[data->n].map_check_y = y / data->map.map_size;
	return (0);
}

int quarter_three_yaxis(t_data *data)
{
	long double tmp_y;
	long double y;

	tmp_y = data->map.map_size - data->player.cell_y;
	y = data->map.map_size * (data->player.map_y + 1);
	data->ray[data->n].tmp_x = data->player.x - (tmp_y * (tan(data->ray[data->n].tmp_angle)));
	data->ray[data->n].map_check_x = data->ray[data->n].tmp_x / data->map.map_size;
	data->ray[data->n].map_check_y = y / data->map.map_size;
	data->ray[data->n].imgx = 60 - (data->ray[data->n].tmp_x - (60 * data->ray[data->n].map_check_x));
	return (0);
}

int quarter_four_yaxis(t_data *data)
{
	long double y;

	y = data->map.map_size * (data->player.map_y - 1);
	data->ray[data->n].tmp_x = data->player.x - (data->player.cell_y /(tan(data->ray[data->n].tmp_angle)));
	data->ray[data->n].map_check_x = data->ray[data->n].tmp_x / data->map.map_size;
	data->ray[data->n].map_check_y = y / data->map.map_size;
	return (0);
}

int check_hor_map(t_data *data)
{
	if (data->ray[data->n].quarter == 1)
		quarter_one_yaxis(data);
	if (data->ray[data->n].quarter == 2)
		quarter_two_yaxis(data);
	if (data->ray[data->n].quarter == 3)
		quarter_three_yaxis(data);
	if (data->ray[data->n].quarter == 4)
		quarter_four_yaxis(data);
	data->ray[data->n].imgx = (data->ray[data->n].tmp_x - (60 * (data->ray[data->n].map_check_x)));
	y_ray_len_check(data);
	return (0);
}
