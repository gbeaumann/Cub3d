#include "../cube.h"

long double fix_fish_eye(t_data *data)
{
    long double angle;
    long double         ray;

    angle = ((data->n - data->max/2) * ((PI/8) /(data->max/2)));
    ray = data->ray[data->n].ray_len * cos(angle);
    return (ray);
}