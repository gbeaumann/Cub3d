#include "../cube.h"

int quarter_one_y_dist(t_data *data)
{
    data->ray[data->n].ray_y = data->player.cell_y/cos(data->ray[data->n].angle);
    return (data->ray[data->n].ray_y);
}

int quarter_two_y_dist(t_data *data)
{
    long double tmp_cell_y;

    tmp_cell_y = 60 - data->player.cell_y;
    data->ray[data->n].ray_y = tmp_cell_y/sin(data->ray[data->n].tmp_angle);
    return (data->ray[data->n].ray_y);
}

int quarter_three_y_dist(t_data *data)
{
    long double tmp_cell_y;

    tmp_cell_y = 60 - data->player.cell_y;
    data->ray[data->n].ray_y = tmp_cell_y/cos(data->ray[data->n].tmp_angle);
    return (data->ray[data->n].ray_y);
}

int quarter_four_y_dist(t_data *data)
{
    data->ray[data->n].ray_y = data->player.cell_y/sin(data->ray[data->n].tmp_angle);
    return (data->ray[data->n].ray_y);
}

int cal_y_dist(t_data *data)
{
    if (data->ray[data->n].quarter == 1)
        quarter_one_y_dist(data);
    if (data->ray[data->n].quarter == 2)
        quarter_two_y_dist(data);
    if (data->ray[data->n].quarter == 3)
        quarter_three_y_dist(data);
    if (data->ray[data->n].quarter == 4)
        quarter_four_y_dist(data);
    check_hor_map(data);
    return (0);
}