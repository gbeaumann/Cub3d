#include "../cube.h"

int quarter_one_y_dist(t_data *img)
{
    long double y_sidedist;

    y_sidedist = img->cell_y/cos(img->angle);
    printf("y_sidedist %Lf\n", y_sidedist);
    return (y_sidedist);
}

int quarter_two_y_dist(t_data *img, long double tmp_angle)
{
    long double tmp_cell_y;
    long double y_sidedist;

    tmp_cell_y = 60 - img->cell_y;
    y_sidedist = tmp_cell_y/sin(tmp_angle);
    printf("y_sidedist %Lf\n", y_sidedist);
    return (y_sidedist);
}

int quarter_three_y_dist(t_data *img, long double tmp_angle)
{
    long double y_sidedist;
    long double tmp_cell_y;

    tmp_cell_y = 60 - img->cell_y;
    y_sidedist = tmp_cell_y/cos(tmp_angle);
    printf("y_sidedist %Lf\n", y_sidedist);
    return (y_sidedist);
}

int quarter_four_y_dist(t_data *img, long double tmp_angle)
{
    long double y_sidedist;

    y_sidedist = img->cell_y/sin(tmp_angle);
    printf("y_sidedist %Lf\n", y_sidedist);
    return (y_sidedist);
}

int cal_y_dist(t_data *img)
{
    long double tmp_angle;

    tmp_angle = 0;
    printf("img->celly: %Lf\n", img->cell_y);
    if (img->quarter == 1)
        quarter_one_y_dist(img);
    if (img->quarter == 2)
    {
        tmp_angle = img->angle - (PI/2);
        quarter_two_y_dist(img, tmp_angle);
    }
    if (img->quarter == 3)
    {
        tmp_angle = img->angle - (PI);
        quarter_three_y_dist(img, tmp_angle);
    }
    if (img->quarter == 4)
    {
        tmp_angle = img->angle - ((3 * PI)/2);
        quarter_four_y_dist(img, tmp_angle);
    }
    printf("tmp_angle %Lf\n", tmp_angle);
    return (0);
}