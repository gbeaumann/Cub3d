#include	"../cube.h"

int backward_one(t_data *data, float pdx, float pdy)
{
    float new_angle;
    int   len;

    if (data->player.angle < PI/4)
    {
        data->player.y += 5;
        data->player.cell_y += 5;
        data->player.x -= 5 * (tan(data->player.angle));
        data->player.cell_x -= 5 * (tan(data->player.angle));
        display_ray(data, pdx, pdy);
    }
    else if (data->player.angle > PI/4)
    {
        new_angle = PI/2 - data->player.angle;
        data->player.x -= 5;
        data->player.cell_x -= 5;
        data->player.y += 5 * (tan(new_angle));
        data->player.cell_y += 5 * (tan(new_angle));
        display_ray(data, pdx, pdy);
    }
    else if (data->player.angle == PI/4)
    {
        data->player.x -= 5;
        data->player.y += 5;
        display_ray(data, pdx, pdy);
    }
    return (0);
}

int backward_two(t_data *data, float pdx, float pdy, float tmp_angle)
{
    float new_angle;
    int   len;

    if (tmp_angle < PI/4)
    {
        data->player.x -= 5;
        data->player.cell_x -= 5;
        data->player.y -= 5 * (tan(tmp_angle));
        data->player.cell_y -= 5 * (tan(tmp_angle));
        display_ray(data, pdx, pdy);
    }
    else if (tmp_angle > PI/4)
    {
        new_angle = PI/2 - tmp_angle;
        data->player.y -= 5;
        data->player.cell_y -= 5;
        data->player.x -= 5 * (tan(new_angle));
        data->player.cell_x -= 5 * (tan(new_angle));
        display_ray(data, pdx, pdy);
    }
    else if (tmp_angle == PI/4)
    {
        data->player.x -= 5;
        data->player.y -= 5;
        display_ray(data, pdx, pdy);
    }
    return (0);
}

int backward_three(t_data *data, float pdx, float pdy, float tmp_angle)
{
    float new_angle;
    int   len;

    if (tmp_angle < PI/4)
    {
        data->player.y -= 5;
        data->player.cell_y -= 5;
        data->player.x += 5 * (tan(tmp_angle));
        data->player.cell_x += 5 * (tan(tmp_angle));
        display_ray(data, pdx, pdy);
    }
    else if (tmp_angle > PI/4)
    {
        new_angle = PI/2 - tmp_angle;
        data->player.x += 5;
        data->player.cell_x += 5;
        data->player.y -= 5 * (tan(new_angle));
        data->player.cell_y -= 5 * (tan(new_angle));
        display_ray(data, pdx, pdy);
    }
    else if (tmp_angle == PI/4)
    {
        data->player.x += 5;
        data->player.y -= 5;
        display_ray(data, pdx, pdy);
    }
    return (0);
}

int backward_four(t_data *data, float pdx, float pdy, float tmp_angle)
{
    float new_angle;
    int   len;

    if (tmp_angle < PI/4)
    {
        data->player.x += 5;
        data->player.cell_x += 5;
        data->player.y += 5 * (tan(tmp_angle));
        data->player.cell_y += 5 * (tan(tmp_angle));
        display_ray(data, pdx, pdy);
    }
    else if (tmp_angle > PI/4)
    {
        new_angle = PI/2 - tmp_angle;
        data->player.y += 5;
        data->player.cell_y += 5;
        data->player.x += 5 * (tan(new_angle));
        data->player.cell_x += 5 * (tan(new_angle));
        display_ray(data, pdx, pdy);
    }
    else if (tmp_angle == PI/4)
    {
        data->player.x += 5;
        data->player.y += 5;
        display_ray(data, pdx, pdy);
    }
    return (0);
}

int backward(t_data *data, float pdx, float pdy)
{
    float   tmp_angle;

    tmp_angle = 0;
    if (data->player.quarter == 1)
        backward_one(data, pdx, pdy);
    if (data->player.quarter == 2)
    {
        tmp_angle = data->player.angle - (PI/2);
        backward_two(data, pdx, pdy, tmp_angle);
    }
    if (data->player.quarter == 3)
    {
        tmp_angle = data->player.angle - (PI);
        backward_three(data, pdx, pdy, tmp_angle);
    }
    if (data->player.quarter == 4)
    {
        tmp_angle = data->player.angle - ((3 * PI)/2);
        backward_four(data, pdx, pdy, tmp_angle);
    }
    return (0);
}
