#include "../cube.h"

int quarter_one_x_dist_long(t_data *data)
{
	data->ray[data->n].ray_x += data->map.map_size/sin(data->ray[data->n].angle);
	data->ray[data->n].map_check_x += 1;
	data->ray[data->n].tmp_y -= (data->map.map_size/tan(data->ray[data->n].angle));
	data->ray[data->n].map_check_y = data->ray[data->n].tmp_y/data->map.map_size;
	return (data->ray[data->n].ray_x);
}

int quarter_two_x_dist_long(t_data *data)
{
	data->ray[data->n].ray_x += data->map.map_size/cos(data->ray[data->n].tmp_angle);
	data->ray[data->n].map_check_x += 1;
	data->ray[data->n].tmp_y += data->map.map_size * (tan(data->ray[data->n].tmp_angle));
	data->ray[data->n].map_check_y = data->ray[data->n].tmp_y/data->map.map_size;
	return (data->ray[data->n].ray_x);
}

int quarter_three_x_dist_long(t_data *data)
{
	data->ray[data->n].ray_x += data->map.map_size/sin(data->ray[data->n].tmp_angle);
	data->ray[data->n].map_check_x -= 1;
	data->ray[data->n].tmp_y += (data->map.map_size/tan(data->ray[data->n].tmp_angle));
	data->ray[data->n].map_check_y = data->ray[data->n].tmp_y/data->map.map_size;
	return (data->ray[data->n].ray_x);
}

int quarter_four_x_dist_long(t_data *data)
{
	data->ray[data->n].ray_x += data->map.map_size/cos(data->ray[data->n].tmp_angle);
	data->ray[data->n].map_check_x -= 1;
	data->ray[data->n].tmp_y -= data->map.map_size * (tan(data->ray[data->n].tmp_angle));
	data->ray[data->n].map_check_y = data->ray[data->n].tmp_y/data->map.map_size;
	return (data->ray[data->n].ray_x);
}

int x_ray_len_check(t_data *data)
{
	while (1)
	{
		if (check_map(data))
			break;
		if (data->ray[data->n].quarter == 1)
			quarter_one_x_dist_long(data);
		if (data->ray[data->n].quarter == 2)
			quarter_two_x_dist_long(data);
		if (data->ray[data->n].quarter == 3)
			quarter_three_x_dist_long(data);
		if (data->ray[data->n].quarter == 4)
			quarter_four_x_dist_long(data);
		data->ray[data->n].imgy = data->ray[data->n].tmp_y - (60 * data->ray[data->n].map_check_y);
	}
	return (0);
}