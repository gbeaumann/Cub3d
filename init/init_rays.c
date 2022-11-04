#include "../cube.h"

void    init_right_ray(t_data *data, int n)
{
    if (data->n == data->max/2)
        data->ray[data->n].rot = data->ray[0].rot + 1;
    else
        data->ray[data->n].rot = data->ray[0].rot;
    data->ray[data->n].angle = (data->ray[0].angle)+ (((PI/8) /(data->max/2)) * n);
    if (data->n == data->max/2)
        data->ray[data->n].init_tmp_angle = 0;
    else
        data->ray[data->n].init_tmp_angle = (((PI/8) /(data->max/2)) * n);
}

void    init_left_ray(t_data *data, int n)
{
    data->ray[data->n].rot = data->ray[0].rot - 1;
    if (data->n == data->max -1)
            data->ray[data->n].init_tmp_angle = 0;
    else
        data->ray[data->n].init_tmp_angle = (PI/8) - (((PI/8) /(data->max/2))* n);
    if (data->ray[0].quarter == 1 )
        data->ray[data->n].angle = (data->ray[0].angle) + ((2 * PI) - ((PI/8) /(data->max/2)) * n);
    else
        data->ray[data->n].angle = (data->ray[0].angle) - (((PI/8) /(data->max/2)) * n);
}


void    init_rays(t_data *data)
{
    data->n = 1;
    while (data->n < data->max)
    {
        data->ray[data->n].map_check_x = 0;
        data->ray[data->n].map_check_y = 0;
        data->ray[data->n].ray_len = 0;
        data->ray[data->n].ray_x = 0;
        data->ray[data->n].ray_y = 0;
        data->ray[data->n].tmp_x = 0;
        data->ray[data->n].tmp_y = 0;
        data->ray[data->n].wall = '\0';
        if (data->n <= data->max/2)
            init_right_ray(data, (data->n ));
        else if (data->n > data->max/2)
            init_left_ray(data, (data->n - data->max/2));
        quarter_calculation(data);
        /*printf("ray %d quarter: %d\n", data->n, data->ray[data->n].quarter);
        printf("ray %d angle: %Lf\n", data->n, data->ray[data->n].angle);
        printf("ray %d rotation: %d\n", data->n, data->ray[data->n].rot);
        printf("ray %d init tmp angle: %Lf\n", data->n, data->ray[data->n].init_tmp_angle);*/
        data->n++;
    }
}