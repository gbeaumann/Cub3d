#include "../cube.h"

int quarter_one_x_dist(t_data *img)
{
    long double tmp_cell_x;
    
    tmp_cell_x = 60 - img->cell_x;
    img->ray_x = tmp_cell_x/sin(img->angle);
    return (img->ray_x);
}

int quarter_two_x_dist(t_data *img)
{
    long double tmp_cell_x;

    tmp_cell_x = 60 - img->cell_x;
    img->ray_x = tmp_cell_x/cos(img->tmp_angle);
    return (img->ray_x);
}

int quarter_three_x_dist(t_data *img)
{
    img->ray_x = img->cell_x/sin(img->tmp_angle);
    return (img->ray_x);
}

int quarter_four_x_dist(t_data *img)
{
    img->ray_x = img->cell_x/cos(img->tmp_angle);
    return (img->ray_x);
}

int cal_x_dist(t_data *img)
{
    printf("img->cellx: %Lf\n", img->cell_x);
    if (img->quarter == 1)
            quarter_one_x_dist(img);
    if (img->quarter == 2)
        quarter_two_x_dist(img);
    if (img->quarter == 3)
        quarter_three_x_dist(img);
    if (img->quarter == 4)
        quarter_four_x_dist(img);
    cal_xaxis(img);
    return (0);
}