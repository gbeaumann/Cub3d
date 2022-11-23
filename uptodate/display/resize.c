#include "../cube.h"

/*float find_delta_x(t_data * data)
{
    int new_n;
    float count;

    count = 0;
    new_n = data->n;
    while (data->ray[new_n].wall == 'S')
    {
        //printf("mapx rays[%d]: %d\n", new_n, data->ray[new_n].map_x);
        new_n++;
        count++;
    }
    count *= 10;
    return (count);
}

float rule_of_three_x(t_data *data)
{
    float prox;
    float deltax;

    //380
    //150
    deltax = find_delta_x(data);
    printf("delta x (nb of rays that hit): %f\n", deltax);
    prox = deltax / 150;
    //prox = find_prox(data);
    return (prox);
}*/

//maybe problems with rounding off
float rule_of_three_y(long double wall_heigth)
{
    float  proy;

    //285
    //92
    proy = ((wall_heigth * 2) / 52);
    return (proy);
}