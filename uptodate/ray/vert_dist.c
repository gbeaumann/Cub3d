#include "../cube.h"

int quarter_one_x_dist(t_data *data)
{
	long double tmp_cell_x;
	
	//printf("player x: %Lf\n", data->player.cell_x);
	tmp_cell_x = data->map.map_size - data->player.cell_x;
	data->ray[data->n].ray_x = tmp_cell_x/sin(data->ray[data->n].angle);
	return (data->ray[data->n].ray_x);
}

int quarter_two_x_dist(t_data *data)
{
	long double tmp_cell_x;

	tmp_cell_x = data->map.map_size - data->player.cell_x;
	data->ray[data->n].ray_x = tmp_cell_x/cos(data->ray[data->n].tmp_angle);
	return (data->ray[data->n].ray_x);
}

int quarter_three_x_dist(t_data *data)
{
	data->ray[data->n].ray_x = data->player.cell_x/sin(data->ray[data->n].tmp_angle);
	return (data->ray[data->n].ray_x);
}

int quarter_four_x_dist(t_data *data)
{
	data->ray[data->n].ray_x = data->player.cell_x/cos(data->ray[data->n].tmp_angle);
	return (data->ray[data->n].ray_x);
}

int cal_x_dist(t_data *data)
{
	printf("player angle: %Lf\n", data->ray[data->ray1].angle);
	//rintf("player angle: %Lf\n", data->ray[data->n].angle);
	printf("quarter: %d\n", data->ray[data->ray1].quarter);
	if (data->ray[data->n].quarter == 1)
		quarter_one_x_dist(data);
	if (data->ray[data->n].quarter == 2)
		quarter_two_x_dist(data);
	if (data->ray[data->n].quarter == 3)
		quarter_three_x_dist(data);
	if (data->ray[data->n].quarter == 4)
		quarter_four_x_dist(data);
	printf("rayx1: %Lf\n", data->ray[71].ray_x);
	check_vert_map(data);
	return (0);
}