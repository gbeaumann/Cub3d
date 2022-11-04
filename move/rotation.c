#include	"../cube.h"

int	quarter_calculation(t_data *data)
{
	if ((data->ray[data->n].angle >= 0) && (data->ray[data->n].angle < PI/2))
	{
		data->ray[data->n].tmp_angle = 0;
		data->ray[data->n].quarter = 1;
	}
	if ((data->ray[data->n].angle >= PI/2) && (data->ray[data->n].angle < PI))
	{
		data->ray[data->n].quarter = 2;
		data->ray[data->n].tmp_angle = data->ray[data->n].angle - (PI/2);
	}
	if ((data->ray[data->n].angle >= PI) && (data->ray[data->n].angle < (3 * PI)/2))
	{
		data->ray[data->n].tmp_angle = data->ray[data->n].angle - (PI);
		data->ray[data->n].quarter = 3;
	}
	if ((data->ray[data->n].angle >= (3 * PI)/2) && (data->ray[data->n].angle < (2 * PI)))
	{
		data->ray[data->n].tmp_angle = data->ray[data->n].angle - ((3 * PI)/2);
		data->ray[data->n].quarter = 4;
	}
	return (0);
}

//test to calculate the rotation of each rays and readjust the value of the angle

int	cal_rot(t_data * data)
{
	if (data->ray[data->n].rot == 16 || data->ray[data->n].rot == -16 || data->ray[data->n].rot == 0)
	{
		data->ray[data->n].rot = 0;
		data->ray[data->n].angle = 0 + data->ray[data->n].init_tmp_angle;
	}
	else if (data->ray[data->n].rot == 4 || data->ray[data->n].rot == -12)
		data->ray[data->n].angle = PI/2 + data->ray[data->n].init_tmp_angle;
	else if (data->ray[data->n].rot == 8 || data->ray[data->n].rot == -8)
		data->ray[data->n].angle = PI + data->ray[data->n].init_tmp_angle;
	else if (data->ray[data->n].rot == 12 || data->ray[data->n].rot == -4)
		data->ray[data->n].angle = 3 * (PI/2) + data->ray[data->n].init_tmp_angle;
	return (0);
}

int	rotation_left(t_data *data)
{
	data->n = 0;
	while (data->n < data->max)
	{
		data->ray[data->n].angle += ((2 * PI) - (PI/8));
		if (data->ray[data->n].angle >= (2 * PI))
			data->ray[data->n].angle -= (2 * PI);
		quarter_calculation(data);
		data->ray[data->n].rot--;
		cal_rot(data);
		data->n++;
	}
	return (0);
}

int	rotation_right(t_data *data)
{
	data->n = 0;
	while (data->n < data->max)
	{
		data->ray[data->n].angle += (PI/8);
		if (data->ray[data->n].angle >= (2 * PI))
			data->ray[data->n].angle -= (2 * PI);
		quarter_calculation(data);
		data->ray[data->n].rot++;
		cal_rot(data);
		data->n++;
	}
	return (0);
}
