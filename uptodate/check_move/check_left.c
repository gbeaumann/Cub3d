#include "../cube.h"

int check_left_one(t_data *data)
{
    long double tmpx;
    long double tmpy;

    tmpx = data->player.cell_x;
    tmpy = data->player.cell_y;
    tmpx -= data->map.move_size * cos(data->ray[0].angle);
    tmpy -=  data->map.move_size * sin(data->ray[0].angle);
    if(set_check(data, tmpx, tmpy))
        return (1);
    return (0);
}

int check_left_two(t_data *data)
{
    long double tmpx;
    long double tmpy;

    tmpx = data->player.cell_x;
    tmpy = data->player.cell_y;
    tmpx += data->map.move_size * sin(data->ray[0].tmp_angle);
    tmpy -= data->map.move_size * cos(data->ray[0].tmp_angle);
    if(set_check(data, tmpx, tmpy))
        return (1);
    return (0);
}

int check_left_three(t_data *data)
{
    long double tmpx;
    long double tmpy;

    tmpx = data->player.cell_x;
    tmpy = data->player.cell_y;
    tmpx += data->map.move_size * cos(data->ray[0].tmp_angle);
    tmpy += data->map.move_size * sin(data->ray[0].tmp_angle);
    if(set_check(data, tmpx, tmpy))
        return (1);
    return (0);
}

int check_left_four(t_data *data)
{
    long double tmpx;
    long double tmpy;

    tmpx = data->player.cell_x;
    tmpy = data->player.cell_y;
    tmpx -= data->map.move_size * sin(data->ray[0].tmp_angle);
    tmpy += data->map.move_size * cos(data->ray[0].tmp_angle);
    if(set_check(data, tmpx, tmpy))
        return (1);
    return (0);
}

int check_left(t_data *data)
{
    if (data->ray[0].quarter == 1)
    {
        if (check_left_one(data))
            return (1);
    }
    if (data->ray[0].quarter == 2)
    {
        if (check_left_two(data))
            return (1);
    }
    if (data->ray[0].quarter == 3)
    {
        if (check_left_three(data))
            return (1);
    }
    if (data->ray[0].quarter == 4)
    {
        if (check_left_four(data))
            return (1);
    }
    return (0);
}