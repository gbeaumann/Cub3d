#include "../cube.h"

int check_map(t_data *data)
{
    if (data->ray[data->n].map_check_x > data->map.map_w || data->ray[data->n].map_check_y > data->map.map_h)
        return (1);
    if (data->ray[data->n].map_check_x < 0 || data->ray[data->n].map_check_y < 0)
        return (1);
    if (data->map.map[data->ray[data->n].map_check_y][data->ray[data->n].map_check_x] == '1')
        return (1);
    return (0);
}

int find_ray_len(t_data *data)
{
   if (exception_len(data))
    {
        cal_x_dist(data);
        cal_y_dist(data);
        if (data->ray[data->n].ray_x < data->ray[data->n].ray_y)
        {
            data->ray[data->n].ray_len = data->ray[data->n].ray_x;
            if (data->ray[data->n].quarter == 1 || data->ray[data->n].quarter == 2)
                data->ray[data->n].wall = 'W';
            else
                data->ray[data->n].wall = 'E';
        }
        else if (data->ray[data->n].ray_x > data->ray[data->n].ray_y)
        {
            data->ray[data->n].ray_len = data->ray[data->n].ray_y;
            if (data->ray[data->n].quarter == 4 || data->ray[data->n].quarter == 1)
                data->ray[data->n].wall = 'S';
            else
                data->ray[data->n].wall = 'N';
        }
        else
            data->ray[data->n].ray_len = data->ray[data->n].ray_x;
    }
    return (0);
}