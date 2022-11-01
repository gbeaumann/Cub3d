#include	"../cube.h"

int forward_one(t_data *data)
{
    float new_angle;
    int   len;

    if (data->ray[0].angle < PI/4)
    {
        data->player.y -= 5;
        data->player.x += 5 * (tan(data->ray[0].angle));
        data->player.cell_y -= 5;
        data->player.cell_x += 5 * (tan(data->ray[0].angle));
    }
    else if (data->ray[0].angle > PI/4)
    {
        new_angle = PI/2 - data->ray[0].angle;
        data->player.x += 5;
        data->player.cell_x += 5;
        data->player.y -= 5 * (tan(new_angle));
        data->player.cell_y -= 5 * (tan(new_angle));
    }
    else if (data->ray[0].angle == PI/4)
    {
        data->player.cell_x += 5;
        data->player.cell_y -= 5;
        data->player.x += 5;
        data->player.y -= 5;
    }
    return (0);
}

int forward_two(t_data *data)
{
    float new_angle;
    int   len;

    if (data->ray[0].tmp_angle < PI/4)
    {
        data->player.x += 5;
        data->player.cell_x += 5;
        data->player.y += 5 * (tan(data->ray[0].tmp_angle));
        data->player.cell_y += 5 * (tan(data->ray[0].tmp_angle));
    }
    else if (data->ray[0].tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->ray[0].tmp_angle;
        data->player.y += 5;
        data->player.cell_y += 5;
        data->player.x += 5 * (tan(new_angle));
        data->player.cell_x += 5 * (tan(new_angle));
    }
    else if (data->ray[0].tmp_angle == PI/4)
    {
        data->player.cell_x += 5;
        data->player.cell_y += 5;
        data->player.x += 5;
        data->player.y += 5;
    }
    return (0);
}

int forward_three(t_data *data)
{
    float new_angle;
    int   len;

    if (data->ray[0].tmp_angle < PI/4)
    {
        data->player.y += 5;
        data->player.cell_y += 5;
        data->player.x -= 5 * (tan(data->ray[0].tmp_angle));
        data->player.cell_x -= 5 * (tan(data->ray[0].tmp_angle));
    }
    else if (data->ray[0].tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->ray[0].tmp_angle;
        data->player.x -= 5;
        data->player.cell_x -= 5;
        data->player.y += 5 * (tan(new_angle));
        data->player.cell_y += 5 * (tan(new_angle));
    }
    else if (data->ray[0].tmp_angle == PI/4)
    {
        data->player.cell_x -= 5;
        data->player.cell_y += 5;
        data->player.x -= 5;
        data->player.y += 5;
    }
    return (0);
}

int forward_four(t_data *data)
{
    float new_angle;
    int   len;

    if (data->ray[0].tmp_angle < PI/4)
    {
        data->player.x -= 5;
        data->player.cell_x -= 5;
        data->player.y -= 5 * (tan(data->ray[0].tmp_angle));
        data->player.cell_y -= 5 * (tan(data->ray[0].tmp_angle));
    }
    else if (data->ray[0].tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->ray[0].tmp_angle;
        data->player.y -= 5;
        data->player.cell_y -= 5;
        data->player.x -= 5 * (tan(new_angle));
        data->player.cell_x -= 5 * (tan(new_angle));
    }
    else if (data->ray[0].tmp_angle == PI/4)
    {
        data->player.cell_x -= 5;
        data->player.cell_y -= 5;
        data->player.x -= 5;
        data->player.y -= 5;
    }
    return (0);
}

int forward(t_data *data)
{
    if (data->ray[0].quarter == 1)
        forward_one(data);
    if (data->ray[0].quarter == 2)
        forward_two(data);
    if (data->ray[0].quarter == 3)
        forward_three(data);
    if (data->ray[0].quarter == 4)
        forward_four(data);
    return (0);
}
