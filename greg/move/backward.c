#include	"../cube.h"

int backward_one(t_data *data)
{
    float new_angle;
    int   len;

    if (data->player.angle < PI/4)
    {
        data->player.y += 5;
        data->player.cell_y += 5;
        data->player.x -= 5 * (tan(data->player.angle));
        data->player.cell_x -= 5 * (tan(data->player.angle));
    }
    else if (data->player.angle > PI/4)
    {
        new_angle = PI/2 - data->player.angle;
        data->player.x -= 5;
        data->player.cell_x -= 5;
        data->player.y += 5 * (tan(new_angle));
        data->player.cell_y += 5 * (tan(new_angle));
    }
    else if (data->player.angle == PI/4)
    {
        data->player.cell_x -= 5;
        data->player.cell_y += 5;
        data->player.x -= 5;
        data->player.y += 5;
    }
    return (0);
}

int backward_two(t_data *data)
{
    float new_angle;
    int   len;

    if (data->player.tmp_angle < PI/4)
    {
        data->player.x -= 5;
        data->player.cell_x -= 5;
        data->player.y -= 5 * (tan(data->player.tmp_angle));
        data->player.cell_y -= 5 * (tan(data->player.tmp_angle));
    }
    else if (data->player.tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->player.tmp_angle;
        data->player.y -= 5;
        data->player.cell_y -= 5;
        data->player.x -= 5 * (tan(new_angle));
        data->player.cell_x -= 5 * (tan(new_angle));
    }
    else if (data->player.tmp_angle == PI/4)
    {
        data->player.cell_x -= 5;
        data->player.cell_y -= 5;
        data->player.x -= 5;
        data->player.y -= 5;
    }
    return (0);
}

int backward_three(t_data *data)
{
    float new_angle;
    int   len;

    if (data->player.tmp_angle < PI/4)
    {
        data->player.y -= 5;
        data->player.cell_y -= 5;
        data->player.x += 5 * (tan(data->player.tmp_angle));
        data->player.cell_x += 5 * (tan(data->player.tmp_angle));
    }
    else if (data->player.tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->player.tmp_angle;
        data->player.x += 5;
        data->player.cell_x += 5;
        data->player.y -= 5 * (tan(new_angle));
        data->player.cell_y -= 5 * (tan(new_angle));
    }
    else if (data->player.tmp_angle == PI/4)
    {
        data->player.cell_x += 5;
        data->player.cell_y -= 5;
        data->player.x += 5;
        data->player.y -= 5;
    }
    return (0);
}

int backward_four(t_data *data)
{
    float new_angle;
    int   len;

    if (data->player.tmp_angle < PI/4)
    {
        data->player.x += 5;
        data->player.cell_x += 5;
        data->player.y += 5 * (tan(data->player.tmp_angle));
        data->player.cell_y += 5 * (tan(data->player.tmp_angle));
    }
    else if (data->player.tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->player.tmp_angle;
        data->player.y += 5;
        data->player.cell_y += 5;
        data->player.x += 5 * (tan(new_angle));
        data->player.cell_x += 5 * (tan(new_angle));
    }
    else if (data->player.tmp_angle == PI/4)
    {
        data->player.cell_x += 5;
        data->player.cell_y += 5;
        data->player.x += 5;
        data->player.y += 5;
    }
    return (0);
}

int backward(t_data *data)
{
    
    if (data->player.quarter == 1)
        backward_one(data);
    if (data->player.quarter == 2)
        backward_two(data);
    if (data->player.quarter == 3)
        backward_three(data);
    if (data->player.quarter == 4)
        backward_four(data);
    return (0);
}
