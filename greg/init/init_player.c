#include "../cube.h"

int init_angle(char dir, t_data *data)
{
    static char count = 0;

    count++;
    if (dir == 'N' && count == 1)
    {
        data->ray.wall = 'S';
        data->player.angle = 0;
        data->player.rot = 0;
        data->player.quarter = 1;
    }
    else if (dir == 'E' && count == 1)
    {
        data->ray.wall = 'W';
        data->player.angle = PI/2;
        data->player.rot = 4;
        data->player.quarter = 2;
    }
    else if (dir == 'S' && count == 1)
    {
        data->ray.wall = 'N';
        data->player.angle = PI;
        data->player.rot = 8;
        data->player.quarter = 3;
    }
    else if (dir == 'W' && count == 1)
    {
        data->ray.wall = 'E';
        data->player.angle = 3*(PI/2);
        data->player.rot = 12;
        data->player.quarter = 4;
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
                if (init_angle(data->map.map[j][i], data) == 1 )
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