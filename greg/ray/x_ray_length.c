#include "../cube.h"

int quarter_one_x_dist_long(t_data *data)
{
    data->ray[data->n].ray_x += 60/sin(data->ray[data->n].angle);
    data->ray[data->n].map_check_x += 1;
    data->ray[data->n].tmp_y -= (60/tan(data->ray[data->n].angle));
    data->ray[data->n].map_check_y = data->ray[data->n].tmp_y/60;
    return (data->ray[data->n].ray_x);
}

int quarter_two_x_dist_long(t_data *data)
{
    data->ray[data->n].ray_x += 60/cos(data->ray[data->n].tmp_angle);
    data->ray[data->n].map_check_x += 1;
    data->ray[data->n].tmp_y += 60 * (tan(data->ray[data->n].tmp_angle));
    data->ray[data->n].map_check_y = data->ray[data->n].tmp_y/60;
    return (data->ray[data->n].ray_x);
}

int quarter_three_x_dist_long(t_data *data)
{
    data->ray[data->n].ray_x += 60/sin(data->ray[data->n].tmp_angle);
    data->ray[data->n].map_check_x -= 1;
    data->ray[data->n].tmp_y += (60/tan(data->ray[data->n].tmp_angle));
    data->ray[data->n].map_check_y = data->ray[data->n].tmp_y/60;
    return (data->ray[data->n].ray_x);
}

int quarter_four_x_dist_long(t_data *data)
{
    data->ray[data->n].ray_x += 60/cos(data->ray[data->n].tmp_angle);
    data->ray[data->n].map_check_x -= 1;
    data->ray[data->n].tmp_y -= 60 * (tan(data->ray[data->n].tmp_angle));
    data->ray[data->n].map_check_y = data->ray[data->n].tmp_y/60;
    return (data->ray[data->n].ray_x);
}

int x_ray_len_check(t_data *data)
{
    while (1)
    {
        /*printf("x ray: %Lf\n", data->ray[data->n].ray_x);
        printf("map x to check vert: %d\n", data->ray[data->n].map_check_x);
        printf("map y to check vert: %d\n", data->ray[data->n].map_check_y);*/
        if (check_map(data))
            break;
        if (data->ray[data->n].quarter == 1)
            quarter_one_x_dist_long(data);
        if (data->ray[data->n].quarter == 2)
            quarter_two_x_dist_long(data);
        if (data->ray[data->n].quarter == 3)
            quarter_three_x_dist_long(data);
        if (data->ray[data->n].quarter == 4)
            quarter_four_x_dist_long(data);
    }
    return (0);
}