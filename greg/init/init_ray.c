#include "../cube.h"

void    init_ray(t_data *data, int i)
{
    data->tabray[i].map_check_x = 0;
    data->tabray[i].map_check_y = 0;
    data->tabray[i].ray_len = 0;
    data->tabray[i].ray_x = 0;
    data->tabray[i].ray_y = 0;
    data->tabray[i].tmp_x = 0;
    data->tabray[i].tmp_y = 0;
    data->tabray[i].wall = '\0';
}


void    init_ray(t_data *data)
{
    int i;

    i = 1;
    while (i < 4)
    {
        if (i <= 2)
            init_left_ray(data, i);
        else
            init_right_ray(data, i);
        i++;
    }
}