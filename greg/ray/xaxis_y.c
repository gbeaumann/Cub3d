#include "../cube.h"

//functions to find the x nd y coordinates of the next 
//intersection with the x axis

int quarter_one_xaxis(t_data *img)
{
    long double x;
    long double tmp_cell_x;
    long double y;

    tmp_cell_x = 60 - img->cell_x;
    x = 60 * (img->map_x + 1);
    y = img->y  - (tmp_cell_x /tan(img->angle));
    img->map_check_x = x /60;
    img->map_check_y = y /60;
    return (0);
}

int quarter_two_xaxis(t_data *img)
{
    long double x;
    long double tmp_cell_x;
    long double y;

    tmp_cell_x = 60 - img->cell_x;
    x = 60 * (img->map_x + 1);
    y = img->y + (tan(img->tmp_angle) * tmp_cell_x);
    img->map_check_x = x /60;
    img->map_check_y = y /60;
    return (0);
}

int quarter_three_xaxis(t_data *img)
{
    long double x;
    long double y;

    x = 60 * (img->map_x - 1);
    y = img->y + (img->cell_x / tan(img->tmp_angle));
    img->map_check_x = x /60;
    img->map_check_y = y /60;
    return (0);
}

int quarter_four_xaxis(t_data *img)
{
    long double x;
    long double y;

    x = 60 * (img->map_x - 1);
    y = img->y - (tan(img->tmp_angle) * img->cell_x);
    img->map_check_x = x /60;
    img->map_check_y = y /60;
    return (0);
}

int cal_xaxis(t_data *img)
{
    printf("map x: %d\n", img->map_x);
    printf("map y: %d\n", img->map_y);
    if (img->quarter == 1)
        quarter_one_xaxis(img);
    if (img->quarter == 2)
        quarter_two_xaxis(img);
    if (img->quarter == 3)
        quarter_three_xaxis(img);
    if (img->quarter == 4)
        quarter_four_xaxis(img);
    check_x_axis_ray_length(img);
    return (0);
}
