#include "../cube.h"

int check_cell(t_data *data)
{
    if (data->player.cell_y < 0)
    {
        data->player.cell_y = 60 - (data->player.cell_y * -1);
        data->player.map_y--;
    }
    if (data->player.cell_x < 0)
    {
        data->player.cell_x = 60 - (data->player.cell_x * -1);
        data->player.map_x--;
    }
    if (data->player.cell_y > 60)
    {
        data->player.cell_y = (data->player.cell_y - 60);
        data->player.map_y++;
    }
    if (data->player.cell_x > 60)
    {
        data->player.cell_x = (data->player.cell_x - 60);
        data->player.map_x++;
    }
    return (0);
}