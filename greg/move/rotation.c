#include	"../cube.h"

int	quarter_calculation(t_data *data)
{
	if ((data->player.angle >= 0) && (data->player.angle < PI/2))
		data->player.quarter = 1;
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

int	rotation_left(t_data *data, float pdx, float pdy)
{
	data->player.angle += ((2 * PI) - (PI/8));
	if (data->player.angle >= (2 * PI))
		data->player.angle -= (2 * PI);
	quarter_calculation(data);
	display_ray(data, pdx, pdy);
	return (0);
}

int	rotation_right(t_data *data, float pdx, float pdy)
{
	data->player.angle += (PI/8);
	if (data->player.angle >= (2 * PI))
		data->player.angle -= (2 * PI);
	quarter_calculation(data);
	display_ray(data, pdx, pdy);
	return (0);
}
