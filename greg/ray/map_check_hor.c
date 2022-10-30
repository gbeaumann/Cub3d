#include "../cube.h"

int quarter_one_yaxis(t_data *data)
{
    long double y;

    y = 60 * (data->player.map_y - 1);
    data->ray.tmp_x = data->player.x + (data->player.cell_y *(tan(data->player.angle)));
    data->ray.map_check_x = data->ray.tmp_x / 60;
    data->ray.map_check_y = y / 60;
    return (0);
}

int quarter_two_yaxis(t_data *data)
{
    long double tmp_y;
    long double y;

    tmp_y = 60 - data->player.cell_y;
    y = 60 * (data->player.map_y + 1);
    data->ray.tmp_x = data->player.x + (tmp_y /(tan (data->player.tmp_angle)));
    data->ray.map_check_x = (data->ray.tmp_x / 60);
    data->ray.map_check_y = y / 60;
    return (0);
}

int quarter_three_yaxis(t_data *data)
{
    long double tmp_y;
    long double y;

    tmp_y = 60 - data->player.cell_y;
    y = 60 * (data->player.map_y + 1);
    data->ray.tmp_x = data->player.x - (tmp_y * (tan(data->player.tmp_angle)));
    data->ray.map_check_x = data->ray.tmp_x / 60;
    data->ray.map_check_y = y / 60;
    return (0);
}

int quarter_four_yaxis(t_data *data)
{
    long double y;

    y = 60 * (data->player.map_y - 1);
    data->ray.tmp_x = data->player.x - (data->player.cell_y /(tan(data->player.tmp_angle)));
    data->ray.map_check_x = data->ray.tmp_x / 60;
    data->ray.map_check_y = y / 60;
    return (0);
}

int check_hor_map(t_data *data)
{
    if (data->player.quarter == 1)
        quarter_one_yaxis(data);
    if (data->player.quarter == 2)
        quarter_two_yaxis(data);
    if (data->player.quarter == 3)
        quarter_three_yaxis(data);
    if (data->player.quarter == 4)
        quarter_four_yaxis(data);
    y_ray_len_check(data);
    return (0);
}