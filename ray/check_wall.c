#include "../cube.h"


//doesn't work!!!
int check_map(t_data *img)
{
    printf("cell where the ray hits: %c\n", img->map[img->map_check_y][img->map_check_x]);
    if (img->map[img->map_check_y][img->map_check_x] == 0)
        return (0);
    return (1);
}