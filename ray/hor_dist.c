#include "../cube.h"

int quarter_one_y_dist(t_data *data)
{
    data->ray.ray_y = data->player.cell_y/cos(data->player.angle);
    return (data->ray.ray_y);
}

int quarter_two_y_dist(t_data *data)
{
    long double tmp_cell_y;

    tmp_cell_y = data->map.map_size - data->player.cell_y;
    data->ray.ray_y = tmp_cell_y/sin(data->player.tmp_angle);
    return (data->ray.ray_y);
}

int quarter_three_y_dist(t_data *data)
{
    long double tmp_cell_y;

    tmp_cell_y = data->map.map_size - data->player.cell_y;
    data->ray.ray_y = tmp_cell_y/cos(data->player.tmp_angle);
    return (data->ray.ray_y);
}

int quarter_four_y_dist(t_data *data)
{
    data->ray.ray_y = data->player.cell_y/sin(data->player.tmp_angle);
    return (data->ray.ray_y);
}

int cal_y_dist(t_data *data)
{
    if (data->player.quarter == 1)
        quarter_one_y_dist(data);
    if (data->player.quarter == 2)
        quarter_two_y_dist(data);
    if (data->player.quarter == 3)
        quarter_three_y_dist(data);
    if (data->player.quarter == 4)
        quarter_four_y_dist(data);
    check_hor_map(data);
    return (0);
}