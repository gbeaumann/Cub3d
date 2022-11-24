#include "../cube.h"

void    init_right_ray(t_data *data, int n)
{
    if (data->n == data->max -1)
    {
        data->ray[data->n].rot = data->ray[data->ray1].rot + 1;
        data->ray[data->n].angle = (data->ray[data->ray1].angle) + (PI/8);
        data->ray[data->n].init_tmp_angle = 0;
    }
    else
    {
        data->ray[data->n].rot = data->ray[data->ray1].rot;
        data->ray[data->n].angle = (data->ray[data->ray1].angle) + (((PI/8) /(data->max/2)) * n);
        data->ray[data->n].init_tmp_angle = (((PI/8) /(data->max/2)) * n);
    }
}

void    init_left_ray(t_data *data, int n)
{
    data->ray[data->n].rot = data->ray[data->ray1].rot - 1;
    if (data->n == 0)
    {
        if (data->ray[data->ray1].wall == 'S')
            data->ray[data->n].angle = (data->ray[data->ray1].angle) + ((2 * PI) - ((PI/8)));
        else 
            data->ray[data->n].angle = (data->ray[data->ray1].angle) - ((PI/8));
        data->ray[data->n].init_tmp_angle = 0;
    } 
    else
    {
        data->ray[data->n].init_tmp_angle = (PI/8) - (((PI/8) /(data->max/2)) * ((data->max/2) - n));
        if (data->ray[data->ray1].quarter == 1)
            data->ray[data->n].angle = (data->ray[data->ray1].angle) + ((2 * PI) - ((PI/8) /(data->max/2)) * ((data->max/2) - n));
        else
            data->ray[data->n].angle = (data->ray[data->ray1].angle) - (((PI/8) /(data->max/2)) * ((data->max/2) - n));
    }
}

void    init_rays(t_data *data)
{
    data->n = 0;
    while (data->n < data->max)
    {
        if (data->n < data->max/2)
            init_left_ray(data, (data->n));
        else if (data->n > data->max/2)
            init_right_ray(data, (data->n - data->max/2));
        quarter_calculation(data);
        data->n++;
    }
    printf("quarter ray 0: %d\n", data->ray[0].quarter);
}