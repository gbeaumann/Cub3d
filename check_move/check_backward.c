#include	"../cube.h"

int check_backward_one(t_data *data)
{
    float new_angle;
    int   len;
    long double tmpx;
    long double tmpy;

    tmpx = data->player.cell_x;
    tmpy = data->player.cell_y ;
    if (data->ray[0].angle < PI/4)
    {
        tmpy += data->map.move_size;
        tmpx -= data->map.move_size * (tan(data->ray[0].angle));
    }
    else if (data->ray[0].angle > PI/4)
    {
        new_angle = PI/2 - data->ray[0].angle;
        tmpx -= data->map.move_size;
        tmpy += data->map.move_size * (tan(new_angle));
    }
    else if (data->ray[0].angle == PI/4)
    {
        tmpx -= data->map.move_size;
        tmpy += data->map.move_size;
    }
    if(set_check(data, tmpx, tmpy))
        return (1);
    return (0);
}

int check_backward_two(t_data *data)
{
    float new_angle;
    int   len;
    long double tmpx;
    long double tmpy;

    tmpx = data->player.cell_x;
    tmpy = data->player.cell_y ;
    if (data->ray[0].tmp_angle < PI/4)
    {
        tmpx -= data->map.move_size;
        tmpy -= data->map.move_size * (tan(data->ray[0].tmp_angle));
    }
    else if (data->ray[0].tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->ray[0].tmp_angle;
        tmpy -= data->map.move_size;
        tmpx -= data->map.move_size * (tan(new_angle));
    }
    else if (data->ray[0].tmp_angle == PI/4)
    {
        tmpx -= data->map.move_size;
        tmpy -= data->map.move_size;
    }
    if(set_check(data, tmpx, tmpy))
        return (1);
    return (0);
}

int check_backward_three(t_data *data)
{
    float new_angle;
    int   len;
    long double tmpx;
    long double tmpy;

    tmpx = data->player.cell_x;
    tmpy = data->player.cell_y ;
    if (data->ray[0].tmp_angle < PI/4)
    {
        tmpy -= data->map.move_size;
        tmpx += data->map.move_size * (tan(data->ray[0].tmp_angle));
    }
    else if (data->ray[0].tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->ray[0].tmp_angle;
        tmpx += data->map.move_size;
        tmpy -= data->map.move_size * (tan(new_angle));
    }
    else if (data->ray[0].tmp_angle == PI/4)
    {
        tmpx += data->map.move_size;
        tmpy -= data->map.move_size;
    }
   if(set_check(data, tmpx, tmpy))
        return (1);
    return (0);
}

int check_backward_four(t_data *data)
{
    float new_angle;
    int   len;
    long double tmpx;
    long double tmpy;

    tmpx = data->player.cell_x;
    tmpy = data->player.cell_y ;
    if (data->ray[0].tmp_angle < PI/4)
    {
        tmpx += data->map.move_size;
        tmpy += data->map.move_size * (tan(data->ray[0].tmp_angle));
    }
    else if (data->ray[0].tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->ray[0].tmp_angle;
        tmpy += data->map.move_size;
        tmpx += data->map.move_size * (tan(new_angle));
    }
    else if (data->ray[0].tmp_angle == PI/4)
    {
        tmpx += data->map.move_size;
        tmpy += data->map.move_size;
    }
    if(set_check(data, tmpx, tmpy))
        return (1);
    return (0);
}

int check_backward(t_data *data)
{
    if (data->ray[0].quarter == 1)
    {
        if (check_backward_one(data))
            return (1);
    }
    if (data->ray[0].quarter == 2)
    {
        if (check_backward_two(data))
            return (1);
    }
    if (data->ray[0].quarter == 3)
    {
        if (check_backward_three(data))
            return (1);
    }
    if (data->ray[0].quarter == 4)
    {
        if (check_backward_four(data))
            return (1);
    }
    return (0);
}
