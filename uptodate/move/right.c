#include "../cube.h"

int right_one(t_data *data)
{
    data->player.x += 5 * cos(data->ray[data->ray1].angle);
    data->player.cell_x +=  5 * cos(data->ray[data->ray1].angle);
    data->player.y +=  5 * sin(data->ray[data->ray1].angle);
    data->player.cell_y +=  5 * sin(data->ray[data->ray1].angle);
    return (0);
}

int right_two(t_data *data)
{
    data->player.x -= 5 * sin(data->ray[data->ray1].tmp_angle);
    data->player.cell_x -= 5 * sin(data->ray[data->ray1].tmp_angle);
    data->player.y += 5 * cos(data->ray[data->ray1].tmp_angle);
    data->player.cell_y += 5 * cos(data->ray[data->ray1].tmp_angle);
    return (0);
}

int right_three(t_data *data)
{
    data->player.x -= 5 * cos(data->ray[data->ray1].tmp_angle);
    data->player.cell_x -= 5 * cos(data->ray[data->ray1].tmp_angle);
    data->player.y -= 5 * sin(data->ray[data->ray1].tmp_angle);
    data->player.cell_y -= 5 * sin(data->ray[data->ray1].tmp_angle);
    return (0);
}

int right_four(t_data *data)
{
    data->player.x += 5 * sin(data->ray[data->ray1].tmp_angle);
    data->player.cell_x += 5 * sin(data->ray[data->ray1].tmp_angle);
    data->player.y -= 5 * cos(data->ray[data->ray1].tmp_angle);
    data->player.cell_y -= 5 * cos(data->ray[data->ray1].tmp_angle);
    return (0);
}

int right(t_data *data)
{
    if (check_right(data))
        return (1);
    if (data->ray[data->ray1].quarter == 1)
        right_one(data);
    if (data->ray[data->ray1].quarter == 2)
        right_two(data);
    if (data->ray[data->ray1].quarter == 3)
        right_three(data);
    if (data->ray[data->ray1].quarter == 4)
        right_four(data);
    return (0);
}