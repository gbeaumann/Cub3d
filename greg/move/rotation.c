#include	"../cube.h"

int	quarter_calculation(t_data *data)
{
	if ((data->player.angle >= 0) && (data->player.angle < PI/2))
	{
		data->player.tmp_angle = 0;
		data->player.quarter = 1;
	}
	if ((data->player.angle >= PI/2) && (data->player.angle < PI))
	{
		data->player.quarter = 2;
		data->player.tmp_angle = data->player.angle - (PI/2);
	}
	if ((data->player.angle >= PI) && (data->player.angle < (3 * PI)/2))
	{
		data->player.tmp_angle = data->player.angle - (PI);
		data->player.quarter = 3;
	}
	if ((data->player.angle >= (3 * PI)/2) && (data->player.angle < (2 * PI)))
	{
		data->player.tmp_angle = data->player.angle - ((3 * PI)/2);
		data->player.quarter = 4;
	}
	return (0);
}

int	cal_rot(t_data * data)
{
	if (data->player.rot == 16 || data->player.rot == -16 || data->player.rot == 0)
	{
		data->player.rot = 0;
		data->player.angle = 0;
	}
	else if (data->player.rot == 4 || data->player.rot == -12)
		data->player.angle = PI/2;
	else if (data->player.rot == 8 || data->player.rot == -8)
		data->player.angle = PI;
	else if (data->player.rot == 12 || data->player.rot == -4)
		data->player.angle = 3 * (PI/2);
	return (0);
}

int	rotation_left(t_data *data)
{
	data->player.angle += ((2 * PI) - (PI/8));
	if (data->player.angle >= (2 * PI))
		data->player.angle -= (2 * PI);
	quarter_calculation(data);
	data->player.rot--;
	cal_rot(data);
	return (0);
}

int	rotation_right(t_data *data)
{
	data->player.angle += (PI/8);
	if (data->player.angle >= (2 * PI))
		data->player.angle -= (2 * PI);
	quarter_calculation(data);
	data->player.rot++;
	cal_rot(data);
	return (0);
}
