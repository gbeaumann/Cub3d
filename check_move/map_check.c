#include "../cube.h"

int cal_x_map_check(long double x)
{
    if (x <= 0)
        return (-1);
    if (x >= 60)
        return (1);
    return (0);
}

int cal_y_map_check(long double y)
{
    if (y <= 0)
        return (-1);
    if (y >= 60)
        return (1);
    return (0);
}

int set_check(t_data *data, long double tmpx, long double tmpy)
{
    int x;
    int y;

    x = cal_x_map_check(tmpx);
    y = cal_y_map_check(tmpy);
    data->ray[0].map_check_x = (data->player.map_x + x);
    data->ray[0].map_check_y = (data->player.map_y + y);
    if (check_map(data))
        return (1);
    return (0);
}