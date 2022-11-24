#include "../cube.h"

int wall_protect(t_data *data)
{
    if (data->player.cell_x > 59 )
    {
        data->player.cell_x -= 1;
        data->player.x -= 1;
    }
    else if (data->player.cell_x < 1 )
    {
        data->player.cell_x += 1;
        data->player.x += 1;
    }
    if (data->player.cell_y > 59)
    {
        data->player.cell_y -= 1;
        data->player.y -= 1;
    }
    else if (data->player.cell_y < 1)
    {
        data->player.cell_y += 1;
        data->player.y += 1;
    }
    return (0);
}