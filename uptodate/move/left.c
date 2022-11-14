#include "../cube.h"

int left_one(t_data *data)
{
    data->player.x -= 5 * cos(data->ray[0].angle);
    data->player.cell_x -=  5 * cos(data->ray[0].angle);
    data->player.y -=  5 * sin(data->ray[0].angle);
    data->player.cell_y -=  5 * sin(data->ray[0].angle);
    return (0);
}

int left_two(t_data *data)
{
    data->player.x += 5 * sin(data->ray[0].tmp_angle);
    data->player.cell_x += 5 * sin(data->ray[0].tmp_angle);
    data->player.y -= 5 * cos(data->ray[0].tmp_angle);
    data->player.cell_y -= 5 * cos(data->ray[0].tmp_angle);
    return (0);
}

int left_three(t_data *data)
{
    data->player.x += 5 * cos(data->ray[0].tmp_angle);
    data->player.cell_x += 5 * cos(data->ray[0].tmp_angle);
    data->player.y += 5 * sin(data->ray[0].tmp_angle);
    data->player.cell_y += 5 * sin(data->ray[0].tmp_angle);
    return (0);
}

int left_four(t_data *data)
{
    data->player.x -= 5 * sin(data->ray[0].tmp_angle);
    data->player.cell_x -= 5 * sin(data->ray[0].tmp_angle);
    data->player.y += 5 * cos(data->ray[0].tmp_angle);
    data->player.cell_y += 5 * cos(data->ray[0].tmp_angle);
    return (0);
}

int left(t_data *data)
{
    if (check_left(data))
        return (1);
    if (data->ray[0].quarter == 1)
        left_one(data);
    if (data->ray[0].quarter == 2)
        left_two(data);
    if (data->ray[0].quarter == 3)
        left_three(data);
    if (data->ray[0].quarter == 4)
        left_four(data);
    return (0);
}