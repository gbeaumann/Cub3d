#include "../cube.h"

int right_one(t_data *data)
{
    data->player.x += data->map.move_size * cos(data->ray[data->ray1].angle);
    data->player.cell_x +=  data->map.move_size * cos(data->ray[data->ray1].angle);
    data->player.y +=  data->map.move_size * sin(data->ray[data->ray1].angle);
    data->player.cell_y +=  data->map.move_size * sin(data->ray[data->ray1].angle);
    return (0);
}

int right_two(t_data *data)
{
    data->player.x -= data->map.move_size * sin(data->ray[data->ray1].tmp_angle);
    data->player.cell_x -= data->map.move_size * sin(data->ray[data->ray1].tmp_angle);
    data->player.y += data->map.move_size * cos(data->ray[data->ray1].tmp_angle);
    data->player.cell_y += data->map.move_size * cos(data->ray[data->ray1].tmp_angle);
    return (0);
}

int right_three(t_data *data)
{
    data->player.x -= data->map.move_size * cos(data->ray[data->ray1].tmp_angle);
    data->player.cell_x -= data->map.move_size * cos(data->ray[data->ray1].tmp_angle);
    data->player.y -= data->map.move_size * sin(data->ray[data->ray1].tmp_angle);
    data->player.cell_y -= data->map.move_size * sin(data->ray[data->ray1].tmp_angle);
    return (0);
}

int right_four(t_data *data)
{
    data->player.x += data->map.move_size * sin(data->ray[data->ray1].tmp_angle);
    data->player.cell_x += data->map.move_size * sin(data->ray[data->ray1].tmp_angle);
    data->player.y -= data->map.move_size * cos(data->ray[data->ray1].tmp_angle);
    data->player.cell_y -= data->map.move_size * cos(data->ray[data->ray1].tmp_angle);
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
    wall_protect(data);
    return (0);
}