#include "../cube.h"

int init_angle_first_ray(char dir, t_data *data)
{
    static char count = 0;

    count++;
    data->ray[0].init_tmp_angle = 0;
    data->ray[0].map_check_x = 0;
    data->ray[0].map_check_y = 0;
    data->ray[0].ray_len = 0;
    data->ray[0].ray_x = 0;
    data->ray[0].ray_y = 0;
    data->ray[0].tmp_x = 0;
    data->ray[0].tmp_y = 0;
    data->ray[0].tmp_angle = 0;
    if (dir == 'N' && count == 1)
    {
        data->ray[0].wall = 'S';
        data->ray[0].angle = 0;
        data->ray[0].rot = 0;
        data->ray[0].quarter = 1;
    }
    else if (dir == 'E' && count == 1)
    {
        data->ray[0].wall = 'W';
        data->ray[0].angle = PI/2;
        data->ray[0].rot = 4;
        data->ray[0].quarter = 2;
    }
    else if (dir == 'S' && count == 1)
    {
        data->ray[0].wall = 'N';
        data->ray[0].angle = PI;
        data->ray[0].rot = 8;
        data->ray[0].quarter = 3;
    }
    else if (dir == 'W' && count == 1)
    {
        data->ray[0].wall = 'E';
        data->ray[0].angle = 3*(PI/2);
        data->ray[0].rot = 12;
        data->ray[0].quarter = 4;
    }
    else
        return (1);
    return (0);
}

int find_pos(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map.map[j])
    {
        i = 0;
        while (data->map.map[j][i])
        {
            if (data->map.map[j][i] != '0' && data->map.map[j][i] != '1')
            {
                if (init_angle_first_ray(data->map.map[j][i], data) == 1 )
                    return (1);
                else
                {
                    data->map.map[j][i] = '0';
                    data->player.map_x = i;
                    data->player.map_y = j;
                }
            }
            i++;
        }
        j++;
    }
    return (0);
}