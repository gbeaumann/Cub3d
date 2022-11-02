#include "../cube.h"

int quarter_one_y_dist_long(t_data *data)
{
    data->ray.ray_y += data->map.map_size/cos(data->player.angle);
    data->ray.map_check_y -= 1;
    data->ray.tmp_x += data->map.map_size * (tan(data->player.angle));
    data->ray.map_check_x = data->ray.tmp_x/data->map.map_size;
    return (data->ray.ray_y);
}

int quarter_two_y_dist_long(t_data *data)
{
    data->ray.ray_y += data->map.map_size/sin(data->player.tmp_angle);
    data->ray.map_check_y += 1;
    data->ray.tmp_x += (data->map.map_size/tan(data->player.tmp_angle));
    data->ray.map_check_x = data->ray.tmp_x/data->map.map_size;
    return (data->ray.ray_y);
}

int quarter_three_y_dist_long(t_data *data)
{
    data->ray.ray_y += data->map.map_size/cos(data->player.tmp_angle);
    data->ray.map_check_y += 1;
    data->ray.tmp_x -= data->map.map_size * (tan(data->player.tmp_angle));
    data->ray.map_check_x = data->ray.tmp_x/data->map.map_size;
    return (data->ray.ray_y);
}

int quarter_four_y_dist_long(t_data *data)
{
    data->ray.ray_y += data->map.map_size/sin(data->player.tmp_angle);
    data->ray.map_check_y -= 1;
    data->ray.tmp_x -= (data->map.map_size/tan(data->player.tmp_angle));
    data->ray.map_check_x = data->ray.tmp_x/data->map.map_size;
    return (data->ray.ray_y);
}

int y_ray_len_check(t_data *data)
{
    while (1)
    {
        /*printf("y ray: %Lf\n", data->ray.ray_y);
        printf("map x to check hor: %d\n", data->ray.map_check_x);
        printf("map y to check hor: %d\n", data->ray.map_check_y);*/
        if (check_map(data))
            break;
        if (data->player.quarter == 1)
            quarter_one_y_dist_long(data);
        if (data->player.quarter == 2)
            quarter_two_y_dist_long(data);
        if (data->player.quarter == 3)
            quarter_three_y_dist_long(data);
        if (data->player.quarter == 4)
            quarter_four_y_dist_long(data);
        /*printf("map x to check hor: %d\n", data->ray.map_check_x);
        printf("map y to check hor: %d\n", data->ray.map_check_y);
        break;*/
    }
    return (0);
}