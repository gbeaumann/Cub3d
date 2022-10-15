#include	"../cube.h"

int forward_one(t_data *img, float pdx, float pdy)
{
    float new_angle;
    int   len;

    if (img->angle < PI/4)
    {
        img->y -= 5;
        img->x += 5 * (tan(img->angle));
        img->cell_y -= 5;
        img->cell_x += 5 * (tan(img->angle));
        display_ray(img, pdx, pdy);
    }
    else if (img->angle > PI/4)
    {
        new_angle = PI/2 - img->angle;
        img->x += 5;
        img->cell_x += 5;
        img->y -= 5 * (tan(new_angle));
        img->cell_y -= 5 * (tan(new_angle));
        display_ray(img, pdx, pdy);
    }
    else if (img->angle == PI/4)
    {
        img->x += 5;
        img->y -= 5;
        display_ray(img, pdx, pdy);
    }
    return (0);
}

int forward_two(t_data *img, float pdx, float pdy, float tmp_angle)
{
    float new_angle;
    int   len;

    if (tmp_angle < PI/4)
    {
        img->x += 5;
        img->cell_x += 5;
        img->y += 5 * (tan(tmp_angle));
        img->cell_y += 5 * (tan(tmp_angle));
        display_ray(img, pdx, pdy);
    }
    else if (tmp_angle > PI/4)
    {
        new_angle = PI/2 - tmp_angle;
        img->y += 5;
        img->cell_y += 5;
        img->x += 5 * (tan(new_angle));
        img->cell_x += 5 * (tan(new_angle));
        display_ray(img, pdx, pdy);
    }
    else if (tmp_angle == PI/4)
    {
        img->x += 5;
        img->y += 5;
        display_ray(img, pdx, pdy);
    }
    return (0);
}

int forward_three(t_data *img, float pdx, float pdy, float tmp_angle)
{
    float new_angle;
    int   len;

    if (tmp_angle < PI/4)
    {
        img->y += 5;
        img->cell_y += 5;
        img->x -= 5 * (tan(tmp_angle));
        img->cell_x -= 5 * (tan(tmp_angle));
        display_ray(img, pdx, pdy);
    }
    else if (tmp_angle > PI/4)
    {
        new_angle = PI/2 - tmp_angle;
        img->x -= 5;
        img->cell_x -= 5;
        img->y += 5 * (tan(new_angle));
        img->cell_y += 5 * (tan(new_angle));
        display_ray(img, pdx, pdy);
    }
    else if (tmp_angle == PI/4)
    {
        img->x -= 5;
        img->y += 5;
        display_ray(img, pdx, pdy);
    }
    return (0);
}

int forward_four(t_data *img, float pdx, float pdy, float tmp_angle)
{
    float new_angle;
    int   len;

    if (tmp_angle < PI/4)
    {
        img->x -= 5;
        img->cell_x -= 5;
        img->y -= 5 * (tan(tmp_angle));
        img->cell_y -= 5 * (tan(tmp_angle));
        display_ray(img, pdx, pdy);
    }
    else if (tmp_angle > PI/4)
    {
        new_angle = PI/2 - tmp_angle;
        img->y -= 5;
        img->cell_y -= 5;
        img->x -= 5 * (tan(new_angle));
        img->cell_x -= 5 * (tan(new_angle));
        display_ray(img, pdx, pdy);
    }
    else if (tmp_angle == PI/4)
    {
        img->x -= 5;
        img->y -= 5;
        display_ray(img, pdx, pdy);
    }
    return (0);
}

int forward(t_data *img, float pdx, float pdy)
{
    float   tmp_angle;

    tmp_angle = 0;
    if (img->quarter == 1)
        forward_one(img, pdx, pdy);
    if (img->quarter == 2)
    {
        tmp_angle = img->angle - (PI/2);
        forward_two(img, pdx, pdy, tmp_angle);
    }
    if (img->quarter == 3)
    {
        tmp_angle = img->angle - (PI);
        forward_three(img, pdx, pdy, tmp_angle);
    }
    if (img->quarter == 4)
    {
        tmp_angle = img->angle - ((3 * PI)/2);
        forward_four(img, pdx, pdy, tmp_angle);
    }
    return (0);
}
