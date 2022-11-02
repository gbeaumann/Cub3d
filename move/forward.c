#include	"../cube.h"

int forward_one(t_data *data)
{
    float new_angle;
    int   len;

    if (data->player.angle < PI/4)
    {
        data->player.y -= data->map.move_size;
        data->player.x += data->map.move_size * (tan(data->player.angle));
        data->player.cell_y -= data->map.move_size;
        data->player.cell_x += data->map.move_size * (tan(data->player.angle));
    }
    else if (data->player.angle > PI/4)
    {
        new_angle = PI/2 - data->player.angle;
        data->player.x += data->map.move_size;
        data->player.cell_x += data->map.move_size;
        data->player.y -= data->map.move_size * (tan(new_angle));
        data->player.cell_y -= data->map.move_size * (tan(new_angle));
    }
    else if (data->player.angle == PI/4)
    {
        data->player.cell_x += data->map.move_size;
        data->player.cell_y -= data->map.move_size;
        data->player.x += data->map.move_size;
        data->player.y -= data->map.move_size;
    }
    return (0);
}

int forward_two(t_data *data)
{
    float new_angle;
    int   len;

    if (data->player.tmp_angle < PI/4)
    {
        data->player.x += data->map.move_size;
        data->player.cell_x += data->map.move_size;
        data->player.y += data->map.move_size * (tan(data->player.tmp_angle));
        data->player.cell_y += data->map.move_size * (tan(data->player.tmp_angle));
    }
    else if (data->player.tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->player.tmp_angle;
        data->player.y += data->map.move_size;
        data->player.cell_y += data->map.move_size;
        data->player.x += data->map.move_size * (tan(new_angle));
        data->player.cell_x += data->map.move_size * (tan(new_angle));
    }
    else if (data->player.tmp_angle == PI/4)
    {
        data->player.cell_x += data->map.move_size;
        data->player.cell_y += data->map.move_size;
        data->player.x += data->map.move_size;
        data->player.y += data->map.move_size;
    }
    return (0);
}

int forward_three(t_data *data)
{
    float new_angle;
    int   len;

    if (data->player.tmp_angle < PI/4)
    {
        data->player.y += data->map.move_size;
        data->player.cell_y += data->map.move_size;
        data->player.x -= data->map.move_size * (tan(data->player.tmp_angle));
        data->player.cell_x -= data->map.move_size * (tan(data->player.tmp_angle));
    }
    else if (data->player.tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->player.tmp_angle;
        data->player.x -= data->map.move_size;
        data->player.cell_x -= data->map.move_size;
        data->player.y += data->map.move_size * (tan(new_angle));
        data->player.cell_y += data->map.move_size * (tan(new_angle));
    }
    else if (data->player.tmp_angle == PI/4)
    {
        data->player.cell_x -= data->map.move_size;
        data->player.cell_y += data->map.move_size;
        data->player.x -= data->map.move_size;
        data->player.y += data->map.move_size;
    }
    return (0);
}

int forward_four(t_data *data)
{
    float new_angle;
    int   len;

    if (data->player.tmp_angle < PI/4)
    {
        data->player.x -= data->map.move_size;
        data->player.cell_x -= data->map.move_size;
        data->player.y -= data->map.move_size * (tan(data->player.tmp_angle));
        data->player.cell_y -= data->map.move_size * (tan(data->player.tmp_angle));
    }
    else if (data->player.tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->player.tmp_angle;
        data->player.y -= data->map.move_size;
        data->player.cell_y -= data->map.move_size;
        data->player.x -= data->map.move_size * (tan(new_angle));
        data->player.cell_x -= data->map.move_size * (tan(new_angle));
    }
    else if (data->player.tmp_angle == PI/4)
    {
        data->player.cell_x -= data->map.move_size;
        data->player.cell_y -= data->map.move_size;
        data->player.x -= data->map.move_size;
        data->player.y -= data->map.move_size;
    }
    return (0);
}

int forward(t_data *data)
{
    if (data->player.quarter == 1)
        forward_one(data);
    if (data->player.quarter == 2)
        forward_two(data);
    if (data->player.quarter == 3)
        forward_three(data);
    if (data->player.quarter == 4)
        forward_four(data);
    return (0);
}
