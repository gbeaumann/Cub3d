#include "../cube.h"

int find_nb_rays(t_data *data, int n)
{
    char c;
    int x;
    int y;

    c = data->ray[n].wall;
    x = data->ray[n].map_x;
    y = data->ray[n].map_y;
    printf("char : %c, mapx: %d\n", c, data->ray[n].map_x);
    while (data->ray[n].wall == c && data->ray[n].map_x == x)
        n++;
    printf("n: %d\n", n);
    return(n);
}

int next_ray_wall_s(t_data *data, t_ray *ray, int n, int dir)
{
    float angle;
    //float angle2;
    float side_len;
    float new_ray_len;
    //float   x_len;
    int x_map;
    float x;

    if (ray->quarter == 1)
    {
        if (dir == 1)
            angle = ray->angle + (n * ((PI/4 )/data->max));
        else if (dir == -1)
            angle = ray->angle - (n * ((PI/4 )/data->max));
        side_len = ray->ray_len * cos(ray->angle);
        new_ray_len = side_len/cos(angle);
        x = new_ray_len * sin(angle);
        x += data->player.cell_x;
        x_map = (x/data->map.map_size) + data->player.map_x;
    }
    else if (ray->quarter == 4)
    {
        printf("okkkkkkk\n");
        if (dir == 1)
            angle = ((PI/2) - ray->tmp_angle) - (n * ((PI/4 )/data->max));
        else if (dir == -1)
            angle = ((PI/2) - ray->tmp_angle) + (n * ((PI/4 )/data->max));
        side_len = ray->ray_len * cos(ray->tmp_angle);
        x = new_ray_len * sin(angle);
        x -= data->player.cell_x;
        x_map = data->player.map_x - (x/data->map.map_size);
        //x += 60 - (data->player.cell_x);
    }
    //x = new_ray_len * (angle);
    printf("angle: %f\n", angle);
    printf("side len: %f\n", side_len);
    printf("new_ray_len: %f\n", new_ray_len);
    printf("map size: %d\n", data->map.map_size);
    printf("x: %f\n", x);
    printf("x_map: %d\n", x_map);
    if (x_map == ray->map_x)
        return (1);
    else
        return (-1);
}

int find_hit_right(t_data *data, int start, int end)
{
    int nb;
    nb = 0;
    end--;
    data->xstart = 0;
    if (data->ray[start].wall == 'S')
    {
        printf("ray end: %d, quarter: %d, ray len: %Lf, mapx: %d\n", end, data->ray[end].quarter, data->ray[end].ray_len, data->ray[end].map_x);
        printf("rayx: %d\n", data->ray[end].map_x);
	    printf("rayy: %d\n", data->ray[end].map_y);
        printf("ray check x: %d\n", data->ray[end].map_check_x);
	    printf("ray check y: %d\n", data->ray[end].map_check_y);
        while (next_ray_wall_s(data, &data->ray[end], nb, 1) != -1)
            nb ++;
        nb--;
        printf("\nray start: %d, quarter: %d, ray len: %Lf, mapx: %d\n\n", start, data->ray[start].quarter, data->ray[start].ray_len, data->ray[start].map_x);
        printf("rayx: %d\n", data->ray[start].map_x);
	    printf("rayy: %d\n", data->ray[start].map_y);
        printf("ray check x: %d\n", data->ray[start].map_check_x);
	    printf("ray check y: %d\n", data->ray[start].map_check_y);
        while (next_ray_wall_s(data, &data->ray[start], nb, -1) != -1)
        {
            data->xstart++;
            nb ++;
        }
        data->xstart--;
        nb--;
    }
    printf("nb in function: %d\n", nb);
    printf("dataxstart int function: %d\n", data->xstart);
    return (nb);
}

float find_prox(t_data *data)
{
    int start;
    int end;
    float nb;
    float prox;

    nb = 0;
    start = data->n;
    end = find_nb_rays(data, start);
    nb = end - start;
    nb += find_hit_right(data, start, end);
    nb *= 10;
    prox = nb/ 150;
    printf("nb: %f\n", nb);
    printf("dataxstart: %d\n", data->xstart);
    return (prox);
}