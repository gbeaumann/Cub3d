#include	"../cube.h"

int backward_one(t_data *data)
{
    float new_angle;
    int   len;

    if (data->ray[data->ray1].angle < PI/4)
    {
        data->player.y += data->map.move_size;
        data->player.cell_y += data->map.move_size;
        data->player.x -= data->map.move_size * (tan(data->ray[data->ray1].angle));
        data->player.cell_x -= data->map.move_size * (tan(data->ray[data->ray1].angle));
    }
    else if (data->ray[data->ray1].angle > PI/4)
    {
        new_angle = PI/2 - data->ray[data->ray1].angle;
        data->player.x -= data->map.move_size;
        data->player.cell_x -= data->map.move_size;
        data->player.y += data->map.move_size * (tan(new_angle));
        data->player.cell_y += data->map.move_size * (tan(new_angle));
    }
    else if (data->ray[data->ray1].angle == PI/4)
    {
        data->player.cell_x -= data->map.move_size;
        data->player.cell_y += data->map.move_size;
        data->player.x -= data->map.move_size;
        data->player.y += data->map.move_size;
    }
    return (0);
}

int backward_two(t_data *data)
{
    float new_angle;
    int   len;

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

int backward_three(t_data *data)
{
    float new_angle;
    int   len;

    if (data->ray[data->ray1].tmp_angle < PI/4)
    {
        data->player.y -= data->map.move_size;
        data->player.cell_y -= data->map.move_size;
        data->player.x += data->map.move_size * (tan(data->ray[data->ray1].tmp_angle));
        data->player.cell_x += data->map.move_size * (tan(data->ray[data->ray1].tmp_angle));
    }
    else if (data->ray[data->ray1].tmp_angle > PI/4)
    {
        new_angle = PI/2 - data->ray[data->ray1].tmp_angle;
        data->player.x += data->map.move_size;
        data->player.cell_x += data->map.move_size;
        data->player.y -= data->map.move_size * (tan(new_angle));
        data->player.cell_y -= data->map.move_size * (tan(new_angle));
    }
    else if (data->ray[data->ray1].tmp_angle == PI/4)
    {
        data->player.cell_x += data->map.move_size;
        data->player.cell_y -= data->map.move_size;
        data->player.x += data->map.move_size;
        data->player.y -= data->map.move_size;
    }
    return (0);
}

int backward_four(t_data *data)
{
    float new_angle;
    int   len;

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

int backward(t_data *data)
{
    if (check_backward(data))
        return (1);
    if (data->ray[data->ray1].quarter == 1)
        backward_one(data);
    if (data->ray[data->ray1].quarter == 2)
        backward_two(data);
    if (data->ray[data->ray1].quarter == 3)
        backward_three(data);
    if (data->ray[data->ray1].quarter == 4)
        backward_four(data);
    return (0);
}
