
#include "../cube.h"

int find_x_pix(t_data * data)
{
    float wall_pos;
    long double   color_x;
    long double cal;

    if (data->ray[data->n].wall == 'S' || data->ray[data->n].wall == 'N')
        wall_pos = data->ray[data->n].imgx;
    else if (data->ray[data->n].wall == 'E' || data->ray[data->n].wall == 'W')
        wall_pos = data->ray[data->n].imgy;
    if ((int)wall_pos == 0)
        return (0);
    cal = wall_pos/((float)60/(float)150);
    color_x = (int)(cal) % 150;
    return (color_x);
}