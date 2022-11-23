#include "../cube.h"

int left_one(t_data *data)
{
    data->player.x -= data->map.move_size * cos(data->ray[data->ray1].angle);
    data->player.cell_x -=  data->map.move_size * cos(data->ray[data->ray1].angle);
    data->player.y -=  data->map.move_size * sin(data->ray[data->ray1].angle);
    data->player.cell_y -=  data->map.move_size * sin(data->ray[data->ray1].angle);
    return (0);
}

int left_two(t_data *data)
{
    data->player.x += data->map.move_size * sin(data->ray[data->ray1].tmp_angle);
    data->player.cell_x += data->map.move_size * sin(data->ray[data->ray1].tmp_angle);
    data->player.y -= data->map.move_size * cos(data->ray[data->ray1].tmp_angle);
    data->player.cell_y -= data->map.move_size * cos(data->ray[data->ray1].tmp_angle);
    return (0);
}

int left_three(t_data *data)
{
    data->player.x += data->map.move_size * cos(data->ray[data->ray1].tmp_angle);
    data->player.cell_x += data->map.move_size * cos(data->ray[data->ray1].tmp_angle);
    data->player.y += data->map.move_size * sin(data->ray[data->ray1].tmp_angle);
    data->player.cell_y += data->map.move_size * sin(data->ray[data->ray1].tmp_angle);
    return (0);
}

int left_four(t_data *data)
{
    data->player.x -= data->map.move_size * sin(data->ray[data->ray1].tmp_angle);
    data->player.cell_x -= data->map.move_size * sin(data->ray[data->ray1].tmp_angle);
    data->player.y += data->map.move_size * cos(data->ray[data->ray1].tmp_angle);
    data->player.cell_y += data->map.move_size * cos(data->ray[data->ray1].tmp_angle);
    return (0);
}

int left(t_data *data)
{
    if (check_left(data))
        return (1);
    if (data->ray[data->ray1].quarter == 1)
        left_one(data);
    if (data->ray[data->ray1].quarter == 2)
        left_two(data);
    if (data->ray[data->ray1].quarter == 3)
        left_three(data);
    if (data->ray[data->ray1].quarter == 4)
        left_four(data);
    return (0);
}