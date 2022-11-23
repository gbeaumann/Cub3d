#include	"../cube.h"

int forward_one(t_data *data)
{
    float new_angle;

    if (data->ray[data->ray1].angle < PI/4)
    {
        data->player.y -= data->map.move_size;
        data->player.x += data->map.move_size * (tan(data->ray[data->ray1].angle));
        data->player.cell_y -= data->map.move_size;
        data->player.cell_x += data->map.move_size * (tan(data->ray[data->ray1].angle));
    }
    else if (data->ray[data->ray1].angle > PI/4)
    {
        new_angle = PI/2 - data->ray[data->ray1].angle;
        data->player.x += data->map.move_size;
        data->player.cell_x += data->map.move_size;
        data->player.y -= data->map.move_size * (tan(new_angle));
        data->player.cell_y -= data->map.move_size * (tan(new_angle));
    }
    else if (data->ray[data->ray1].angle == PI/4)
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

    if (data->ray[data->ray1].tmp_angle < PI/4)
    {
        data->player.x += data->map.move_size;
        data->player.cell_x += data->map.move_size;
        data->player.y += data->map.move_size * (tan(data->ray[data->ray1].tmp_angle));
        data->player.cell_y += data->map.move_size * (tan(data->ray[data->ray1].tmp_angle));
    }
    else if (data->ray[data->ray1].tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->ray[data->ray1].tmp_angle;
        data->player.y += data->map.move_size;
        data->player.cell_y += data->map.move_size;
        data->player.x += data->map.move_size * (tan(new_angle));
        data->player.cell_x += data->map.move_size * (tan(new_angle));
    }
    else if (data->ray[data->ray1].tmp_angle == PI/4)
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

    if (data->ray[data->ray1].tmp_angle < PI/4)
    {
        data->player.y += data->map.move_size;
        data->player.cell_y += data->map.move_size;
        data->player.x -= data->map.move_size * (tan(data->ray[data->ray1].tmp_angle));
        data->player.cell_x -= data->map.move_size * (tan(data->ray[data->ray1].tmp_angle));
    }
    else if (data->ray[data->ray1].tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->ray[data->ray1].tmp_angle;
        data->player.x -= data->map.move_size;
        data->player.cell_x -= data->map.move_size;
        data->player.y += data->map.move_size * (tan(new_angle));
        data->player.cell_y += data->map.move_size * (tan(new_angle));
    }
    else if (data->ray[data->ray1].tmp_angle == PI/4)
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

    if (data->ray[data->ray1].tmp_angle < PI/4)
    {
        data->player.x -= data->map.move_size;
        data->player.cell_x -= data->map.move_size;
        data->player.y -= data->map.move_size * (tan(data->ray[data->ray1].tmp_angle));
        data->player.cell_y -= data->map.move_size * (tan(data->ray[data->ray1].tmp_angle));
    }
    else if (data->ray[data->ray1].tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->ray[data->ray1].tmp_angle;
        data->player.y -= data->map.move_size;
        data->player.cell_y -= data->map.move_size;
        data->player.x -= data->map.move_size * (tan(new_angle));
        data->player.cell_x -= data->map.move_size * (tan(new_angle));
    }
    else if (data->ray[data->ray1].tmp_angle == PI/4)
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
    if (check_forward(data))
        return (1);
    if (data->ray[data->ray1].quarter == 1)
        forward_one(data);
    if (data->ray[data->ray1].quarter == 2)
        forward_two(data);
    if (data->ray[data->ray1].quarter == 3)
        forward_three(data);
    if (data->ray[data->ray1].quarter == 4)
        forward_four(data);
    return (0);
}
