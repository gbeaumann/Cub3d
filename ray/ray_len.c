#include "../cube.h"

int check_map(t_data *data)
{
    if (data->ray.map_check_x > data->map.map_w || data->ray.map_check_y > data->map.map_h)
        return (1);
    if (data->ray.map_check_x < 0 || data->ray.map_check_y < 0)
        return (1);
    if (data->map.map[data->ray.map_check_y][data->ray.map_check_x] == '1')
        return (1);
    return (0);
}

int find_ray_len(t_data *data)
{
    if (exception_len(data))
    {
        cal_x_dist(data);
        cal_y_dist(data);
        if (data->ray.ray_x < data->ray.ray_y)
        {
            data->ray.ray_len = data->ray.ray_x;
            if (data->player.quarter == 1 || data->player.quarter == 2)
                data->ray.wall = 'W';
            else
                data->ray.wall = 'E';
        }
        else if (data->ray.ray_x > data->ray.ray_y)
        {
            data->ray.ray_len = data->ray.ray_y;
            if (data->player.quarter == 4 || data->player.quarter == 1)
                data->ray.wall = 'S';
            else
                data->ray.wall = 'N';
        }
        else
            data->ray.ray_len = data->ray.ray_x;
    }
    //printf("Wall texture to display: %c\n", data->ray.wall);
    /*printf("angle : %Lf\n", data->player.angle);
    printf("player cell x: %Lf\n",data->player.cell_x);
    printf("player cell y: %Lf\n",data->player.cell_y);
    printf("player map x: %d\n",data->player.map_x);
    printf("player mapy: %d\n",data->player.map_y);
    printf("quarte: %d\n", data->player.quarter);
    printf("ray len ==== %d\n", data->ray.ray_len);*/
    return (0);
}