#include "../cube.h"

int check_right_one(t_data *data)
{
    long double tmpx;
    long double tmpy;

    tmpx = data->player.cell_x;
    tmpy = data->player.cell_y;
    tmpx += 5 * cos(data->ray[0].angle);
    tmpy +=  5 * sin(data->ray[0].angle);
    if(set_check(data, tmpx, tmpy))
        return (1);
    return (0);
}

int check_right_two(t_data *data)
{
    long double tmpx;
    long double tmpy;

    tmpx = data->player.cell_x;
    tmpy = data->player.cell_y ;
    tmpx -= 5 * sin(data->ray[0].tmp_angle);
    tmpy += 5 * cos(data->ray[0].tmp_angle);
    if(set_check(data, tmpx, tmpy))
        return (1);
    return (0);
}

int check_right_three(t_data *data)
{
    long double tmpx;
    long double tmpy;

    tmpx = data->player.cell_x;
    tmpy = data->player.cell_y;
    tmpx -= 5 * cos(data->ray[0].tmp_angle);
    tmpy -= 5 * sin(data->ray[0].tmp_angle);
    if(set_check(data, tmpx, tmpy))
        return (1);
    return (0);
}

int check_right_four(t_data *data)
{
    long double tmpx;
    long double tmpy;

    tmpx = data->player.cell_x;
    tmpy = data->player.cell_y;
    tmpx += 5 * sin(data->ray[0].tmp_angle);
    tmpy -= 5 * cos(data->ray[0].tmp_angle);
    if(set_check(data, tmpx, tmpy))
        return (1);
    return (0);
}

int check_right(t_data *data)
{
    if (data->ray[0].quarter == 1)
    {
        if (check_right_one(data))
            return (1);
    }
    if (data->ray[0].quarter == 2)
    {
        if (check_right_two(data))
            return (1);
    }
    if (data->ray[0].quarter == 3)
    {
        if (check_right_three(data))
            return (1);
    }
    if (data->ray[0].quarter == 4)
    {
        if (check_right_four(data))
            return (1);
    }
    return (0);
}