#include "../cube.h"

int init_angle_first_ray(char dir, t_data *data)
{
    static char count = 0;

    if (dir == 'N')
    {
        data->ray[data->ray1].wall = 'S';
        data->ray[data->ray1].angle = 0;
        data->ray[data->ray1].rot = 0;
        data->ray[data->ray1].quarter = 1;
        count++;
    }
    else if (dir == 'E')
    {
        data->ray[data->ray1].wall = 'W';
        data->ray[data->ray1].angle = PI/2;
        data->ray[data->ray1].rot = 4;
        data->ray[data->ray1].quarter = 2;
        count++;
    }
    else if (dir == 'S')
    {
        data->ray[data->ray1].wall = 'N';
        data->ray[data->ray1].angle = PI;
        data->ray[data->ray1].rot = 8;
        data->ray[data->ray1].quarter = 3;
        count++;
    }
    else if (dir == 'W')
    {
        data->ray[data->ray1].wall = 'E';
        data->ray[data->ray1].angle = 3*(PI/2);
        data->ray[data->ray1].rot = 12;
        data->ray[data->ray1].quarter = 4;
        count++;
    }
    return (count);
}

int find_pos(t_data *data)
{
    int i;
    int j;
    int p;

    i = 0;
    j = 0;
    p = 0;
    printf("p : %d\n", p);
    while (data->map.map[j])
    {
        i = 0;
        while (data->map.map[j][i])
        {
            p = init_angle_first_ray(data->map.map[j][i], data);
            if (data->map.map[j][i] != '0' && data->map.map[j][i] != '1' 
            && data->map.map[j][i] != '.')
            {
                data->map.map[j][i] = '0';
                data->player.map_x = i;
                data->player.map_y = j;
            }
            i++;
        }
        j++;
    }
    if (p != 1)
        return (1);
    return (0);
}