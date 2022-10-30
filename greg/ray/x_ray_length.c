#include "../cube.h"

int quarter_one_x_dist_long(t_data *data)
{
    data->ray.ray_x += 60/sin(data->player.angle);
    data->ray.map_check_x += 1;
    data->ray.tmp_y -= (60/tan(data->player.angle));
    data->ray.map_check_y = data->ray.tmp_y/60;
    return (data->ray.ray_x);
}

int quarter_two_x_dist_long(t_data *data)
{
    data->ray.ray_x += 60/cos(data->player.tmp_angle);
    data->ray.map_check_x += 1;
    data->ray.tmp_y += 60 * (tan(data->player.tmp_angle));
    data->ray.map_check_y = data->ray.tmp_y/60;
    return (data->ray.ray_x);
}

int quarter_three_x_dist_long(t_data *data)
{
    data->ray.ray_x += 60/sin(data->player.tmp_angle);
    data->ray.map_check_x -= 1;
    data->ray.tmp_y += (60/tan(data->player.tmp_angle));
    data->ray.map_check_y = data->ray.tmp_y/60;
    return (data->ray.ray_x);
}

int quarter_four_x_dist_long(t_data *data)
{
    data->ray.ray_x += 60/cos(data->player.tmp_angle);
    data->ray.map_check_x -= 1;
    data->ray.tmp_y -= 60 * (tan(data->player.tmp_angle));
    data->ray.map_check_y = data->ray.tmp_y/60;
    return (data->ray.ray_x);
}

int x_ray_len_check(t_data *data)
{
    while (1)
    {
        /*printf("x ray: %Lf\n", data->ray.ray_x);
        printf("map x to check vert: %d\n", data->ray.map_check_x);
        printf("map y to check vert: %d\n", data->ray.map_check_y);*/
        if (check_map(data))
            break;
        if (data->player.quarter == 1)
            quarter_one_x_dist_long(data);
        if (data->player.quarter == 2)
            quarter_two_x_dist_long(data);
        if (data->player.quarter == 3)
            quarter_three_x_dist_long(data);
        if (data->player.quarter == 4)
            quarter_four_x_dist_long(data);
    }
    return (0);
}