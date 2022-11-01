#include "../cube.h"

int quarter_one_y_dist_long(t_data *data)
{
    data->ray[data->n].ray_y += 60/cos(data->ray[data->n].angle);
    data->ray[data->n].map_check_y -= 1;
    data->ray[data->n].tmp_x += 60 * (tan(data->ray[data->n].angle));
    data->ray[data->n].map_check_x = data->ray[data->n].tmp_x/60;
    return (data->ray[data->n].ray_y);
}

int quarter_two_y_dist_long(t_data *data)
{
    data->ray[data->n].ray_y += 60/sin(data->ray[data->n].tmp_angle);
    data->ray[data->n].map_check_y += 1;
    data->ray[data->n].tmp_x += (60/tan(data->ray[data->n].tmp_angle));
    data->ray[data->n].map_check_x = data->ray[data->n].tmp_x/60;
    return (data->ray[data->n].ray_y);
}

int quarter_three_y_dist_long(t_data *data)
{
    data->ray[data->n].ray_y += 60/cos(data->ray[data->n].tmp_angle);
    data->ray[data->n].map_check_y += 1;
    data->ray[data->n].tmp_x -= 60 * (tan(data->ray[data->n].tmp_angle));
    data->ray[data->n].map_check_x = data->ray[data->n].tmp_x/60;
    return (data->ray[data->n].ray_y);
}

int quarter_four_y_dist_long(t_data *data)
{
    data->ray[data->n].ray_y += 60/sin(data->ray[data->n].tmp_angle);
    data->ray[data->n].map_check_y -= 1;
    data->ray[data->n].tmp_x -= (60/tan(data->ray[data->n].tmp_angle));
    data->ray[data->n].map_check_x = data->ray[data->n].tmp_x/60;
    return (data->ray[data->n].ray_y);
}

int y_ray_len_check(t_data *data)
{
    while (1)
    {
        /*printf("y ray: %Lf\n", data->ray[data->n].ray_y);
        printf("map x to check hor: %d\n", data->ray[data->n].map_check_x);
        printf("map y to check hor: %d\n", data->ray[data->n].map_check_y);*/
        if (check_map(data))
            break;
        if (data->ray[data->n].quarter == 1)
            quarter_one_y_dist_long(data);
        if (data->ray[data->n].quarter == 2)
            quarter_two_y_dist_long(data);
        if (data->ray[data->n].quarter == 3)
            quarter_three_y_dist_long(data);
        if (data->ray[data->n].quarter == 4)
            quarter_four_y_dist_long(data);
        /*printf("map x to check hor: %d\n", data->ray[data->n].map_check_x);
        printf("map y to check hor: %d\n", data->ray[data->n].map_check_y);
        break;*/
    }
    return (0);
}