#include "../cube.h"

int init_angle_first_ray(char dir, t_data *data)
{
    static char count = 0;

    count++;
    if (dir == 'N' && count == 1)
    {
        data->ray[data->ray1].wall = 'S';
        data->ray[data->ray1].angle = 0;
        data->ray[data->ray1].rot = 0;
        data->ray[data->ray1].quarter = 1;
    }
    else if (dir == 'E' && count == 1)
    {
        data->ray[data->ray1].wall = 'W';
        data->ray[data->ray1].angle = PI/2;
        data->ray[data->ray1].rot = 4;
        data->ray[data->ray1].quarter = 2;
    }
    else if (dir == 'S' && count == 1)
    {
        data->ray[data->ray1].wall = 'N';
        data->ray[data->ray1].angle = PI;
        data->ray[data->ray1].rot = 8;
        data->ray[data->ray1].quarter = 3;
    }
    else if (dir == 'W' && count == 1)
    {
        data->ray[data->ray1].wall = 'E';
        data->ray[data->ray1].angle = 3*(PI/2);
        data->ray[data->ray1].rot = 12;
        data->ray[data->ray1].quarter = 4;
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
            if (data->map.map[j][i] != '0' && data->map.map[j][i] != '1' 
            && data->map.map[j][i] != '.')
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
    printf("map x: %d\n", data->player.map_x);
    printf("map y: %d\n", data->player.map_y);
    printf("wall: %c\n", data->ray[data->ray1].wall);
    return (0);
}