#include "../cube.h"

int quarter_one_x_dist_long(t_data *img)
{
    img->ray_x = 60/sin(img->angle);
    img->map_check_x += 1;
    img->map_check_y -= (60/tan(img->angle))/60;
    return (img->ray_x);
}

int quarter_two_x_dist_long(t_data *img)
{
    img->ray_x = 60/cos(img->tmp_angle);
    img->map_check_x += 1;
    img->map_check_y += (tan(img->tmp_angle));
    return (img->ray_x);
}

int quarter_three_x_dist_long(t_data *img)
{
    img->ray_x = 60/sin(img->tmp_angle);
    img->map_check_x -= 1;
    img->map_check_y += (60/tan(img->tmp_angle))/60;
    return (img->ray_x);
}

int quarter_four_x_dist_long(t_data *img)
{
    img->ray_x = 60/cos(img->tmp_angle);
    img->map_check_x -= 1;
    img->map_check_y -= (tan(img->angle));
    return (img->ray_x);
}

int check_x_axis_ray_length(t_data *img)
{
    while (1)
    {
        if (check_map(img))
            break;
        if (img->quarter == 1)
            quarter_one_x_dist_long(img);
        if (img->quarter == 2)
            quarter_two_x_dist_long(img);
        if (img->quarter == 3)
            quarter_three_x_dist_long(img);
        if (img->quarter == 4)
            quarter_four_x_dist_long(img);
    }
    printf("img->ray_x %Lf\n", img->ray_x);
    printf("x coordinate of the cell to check: %d\n", img->map_check_x);
    printf("y coordinate of the cell to check: %d\n", img->map_check_y);
    return (0);
}