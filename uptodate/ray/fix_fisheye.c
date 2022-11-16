#include "../cube.h"

int fix_fish_eye(t_data *data)
{
    long double angle;
    long double         ray;

    if (data->n <= data->max/2)
    {
        angle = data->n * ((PI/8) /(data->max/2));
        ray = data->ray[data->n].ray_len * cos(angle);
    }
    else if (data->n > data->max/2)
    {
        angle = ((data->n - data->max/2) * ((PI/8) /(data->max/2)));
        ray = data->ray[data->n].ray_len * cos(angle);
    }
    printf("ray[%d]: %Lf\n", data->n, ray);
    return (ray);
}

/*
.. find which cell does the ray hit and on which wall;
.. stock the cell coordinates;
.. divide the ray length calculation and the display;
.. if the ray next to it is not the same size calculate the dif;
.. if (data->n <= data->max/2)
..  -> if (r0 < r1)
        ->dif = r1 - r0;
        ->dif = dif/whatwewant;
        -> display r0 + dif;
    -> if (r0 > r1)
        ->dif = r0 - r1;
        ->dif = dif/whatwewant;
        -> display r0 + dif;
    else the other way around   
*/

/*int correct_perspective(t_data *data)
{
    int next;
    int dif;
    
    next = data->n;
    if (data->n >= data->max)
        return (0);
    while (data->ray[next].map_x == data->ray[next + 1].map_x
    && data->ray[next].map_y == data->ray[next + 1].map_y
    && data->ray[next].wall == data->ray[next + 1].wall)
        next++;
    next--;
    dif = data->ray[data->n].ray_len - data->ray[next].ray_len;
    dif = dif/((next-data->n) * 5);
    return (dif);
}*/