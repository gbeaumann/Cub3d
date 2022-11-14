#include "../cube.h"

//functions to find the x nd y coordinates of the next 
//intersection with the x axis

int quarter_one_xaxis(t_data *data)
{
    long double x;
    long double tmp_cell_x;

    tmp_cell_x = data->map.map_size - data->player.cell_x;
    x = data->map.map_size * (data->player.map_x + 1);
    data->ray[data->n].tmp_y = data->player.y  - (tmp_cell_x /tan(data->ray[data->n].angle));
    data->ray[data->n].map_check_x = x /data->map.map_size;
    data->ray[data->n].map_check_y = data->ray[data->n].tmp_y /data->map.map_size;
    return (0);
}

int quarter_two_xaxis(t_data *data)
{
    long double x;
    long double tmp_cell_x;

    tmp_cell_x = data->map.map_size - data->player.cell_x;
    x = data->map.map_size * (data->player.map_x + 1);
    data->ray[data->n].tmp_y = data->player.y + (tan(data->ray[data->n].tmp_angle) * tmp_cell_x);
    data->ray[data->n].map_check_x = x /data->map.map_size;
    data->ray[data->n].map_check_y = data->ray[data->n].tmp_y /data->map.map_size;
    return (0);
}

int quarter_three_xaxis(t_data *data)
{
    long double x;

    x = data->map.map_size * (data->player.map_x - 1);
    data->ray[data->n].tmp_y = data->player.y + (data->player.cell_x / tan(data->ray[data->n].tmp_angle));
    data->ray[data->n].map_check_x = x /data->map.map_size;
    data->ray[data->n].map_check_y = data->ray[data->n].tmp_y /data->map.map_size;
    return (0);
}

int quarter_four_xaxis(t_data *data)
{
    long double x;

    x = data->map.map_size * (data->player.map_x - 1);
    data->ray[data->n].tmp_y = data->player.y - (tan(data->ray[data->n].tmp_angle) * data->player.cell_x);
    data->ray[data->n].map_check_x = x /data->map.map_size;
    data->ray[data->n].map_check_y = data->ray[data->n].tmp_y /data->map.map_size;
    return (0);
}

int check_vert_map(t_data *data)
{
    if (data->ray[data->n].quarter == 1)
        quarter_one_xaxis(data);
    if (data->ray[data->n].quarter == 2)
        quarter_two_xaxis(data);
    if (data->ray[data->n].quarter == 3)
        quarter_three_xaxis(data);
    if (data->ray[data->n].quarter == 4)
        quarter_four_xaxis(data);
    x_ray_len_check(data);
    return (0);
}
