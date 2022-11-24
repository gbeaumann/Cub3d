#include "../cube.h"

//checks if the next line (going up) contains smt not part of a map
//retunrs the size of the line or -1

int check_walls_j(t_data *data, int i, int j)
{
    if (j < data->map.tab_size - 1)
    {
        if (data->map.map[j + 1][i] != '1' && data->map.map[j + 1][i] != 'N' &&
        data->map.map[j + 1][i] != 'S' && data->map.map[j + 1][i] != 'W' && 
        data->map.map[j + 1][i] != 'E' && data->map.map[j + 1][i] != '0')
        return (1);
    }
    else
        return (1);
    if (j > 0)
    {
        if (data->map.map[j - 1][i] != '1' && data->map.map[j - 1][i] != 'N' &&
        data->map.map[j - 1][i] != 'S' && data->map.map[j - 1][i] != 'W' && 
        data->map.map[j - 1][i] != 'E' && data->map.map[j - 1][i] != '0')
        return (1);
    }
    else
        return (1);
    return (0);
}

int check_walls_i(t_data *data, int i, int j)
{
    if (i < data->map.line_size - 1)
    {
        if (data->map.map[j][i + 1] != '1' && data->map.map[j][i + 1] != 'N' &&
        data->map.map[j][i + 1] != 'S' && data->map.map[j][i + 1] != 'W' && 
        data->map.map[j][i + 1] != 'E' && data->map.map[j][i + 1] != '0')
        return (1);
    }
    else
        return (1);
    if (i > 0)
    {
        if (data->map.map[j][i - 1] != '1' && data->map.map[j][i - 1] != 'N' &&
        data->map.map[j][i - 1] != 'S' && data->map.map[j][i - 1] != 'W' && 
        data->map.map[j][i - 1] != 'E' && data->map.map[j][i - 1] != '0')
        return (1);
    }
    else
        return (1);
    return (0);
}

int check_map_walls(t_data *data)
{
    int i;
    int j;

    j = 0;
    printf("ok=================\n");
    while (data->map.map[j])
    {
        i = 0;
        while (data->map.map[j][i])
        {
            if (data->map.map[j][i] == '0' || data->map.map[j][i] == 'S'
            || data->map.map[j][i] == 'N' || data->map.map[j][i] == 'W' ||
            data->map.map[j][i] == 'E')
            {
                if (check_walls_i(data, i, j) || 
                check_walls_j(data, i, j))
                {
                    return (1);
                }
            }
            i++;
        }
        j++;
    }
    return (0);
}