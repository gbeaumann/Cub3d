#include "../cube.h"

int find_south_wall(t_data *data)
{
    int y;

    y = data->player.map_y;
    while (data->map.map[y][data->player.map_x] != '1')
        y--;
    data->ray.ray_len = ((data->player.map_y - 1 - y) * data->map.map_size) + data->player.cell_y;
    data->ray.wall = 'S';
    return (0);
}

int find_west_wall(t_data *data)
{
    int x;

    x = data->player.map_x;
    while (data->map.map[data->player.map_y][x] != '1')
        x++;
    data->ray.ray_len = ((x - data->player.map_x - 1) * data->map.map_size) + (data->map.map_size - data->player.cell_x);
    data->ray.wall = 'W';
    return (0);
}

int find_north_wall(t_data *data)
{
    int y;

    y = data->player.map_y;
    while (data->map.map[y][data->player.map_x] != '1')
        y++;
    data->ray.ray_len = ((y - data->player.map_y - 1) * data->map.map_size) + (data->map.map_size - data->player.cell_y);
    data->ray.wall = 'N';
    return (0);
}

int find_east_wall(t_data *data)
{
    int x;

    x = data->player.map_x;
    while (data->map.map[data->player.map_y][x] != '1')
        x--;
    data->ray.ray_len = ((data->player.map_x - 1 - x) * data->map.map_size) + (data->player.cell_x);
    data->ray.wall = 'E';
    return (0);
}

int exception_len(t_data *data)
{
    if (data->player.angle == 0 || data->player.angle == (2 * PI))
        find_south_wall(data);
    else if (data->player.angle == PI/2)
        find_west_wall(data);
    else if (data->player.angle == PI)
        find_north_wall(data);
    else if (data->player.angle == (3 * (PI/2)))
        find_east_wall(data);
    else
        return (1);
    return (0);
}