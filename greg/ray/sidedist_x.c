#include "../cube.h"

int quarter_one_x_dist(t_data *data)
{
    long double tmp_cell_x;
    
    tmp_cell_x = 60 - data->player.cell_x;
    data->ray.ray_x = tmp_cell_x/sin(data->player.angle);
    return (data->ray.ray_x);
}

int quarter_two_x_dist(t_data *data)
{
    long double tmp_cell_x;

    tmp_cell_x = 60 - data->player.cell_x;
    data->ray.ray_x = tmp_cell_x/cos(data->player.tmp_angle);
    return (data->ray.ray_x);
}

int quarter_three_x_dist(t_data *data)
{
    data->ray.ray_x = data->player.cell_x/sin(data->player.tmp_angle);
    return (data->ray.ray_x);
}

int quarter_four_x_dist(t_data *data)
{
    data->ray.ray_x = data->player.cell_x/cos(data->player.tmp_angle);
    return (data->ray.ray_x);
}

int cal_x_dist(t_data *data)
{
    printf("data->cellx: %Lf\n", data->player.cell_x);
    if (data->player.quarter == 1)
            quarter_one_x_dist(data);
    if (data->player.quarter == 2)
        quarter_two_x_dist(data);
    if (data->player.quarter == 3)
        quarter_three_x_dist(data);
    if (data->player.quarter == 4)
        quarter_four_x_dist(data);
    //cal_xaxis(data);
    return (0);
}