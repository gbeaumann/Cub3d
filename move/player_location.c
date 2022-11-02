#include "../cube.h"

int check_cell(t_data *data)
{
    //entering a cell from the south (y = 0)
    if (data->player.cell_y < 0)
    {
        printf("You have entered a new cell from the south\n");
        data->player.cell_y = data->map.map_size - (data->player.cell_y * -1);
        data->player.map_y--;
    }

    //entering a cell from the east side (x = 0)
    if (data->player.cell_x < 0)
    {
        printf("You have entered a new cell from the East\n");
        data->player.cell_x = data->map.map_size - (data->player.cell_x * -1);
        data->player.map_x--;
    }

    //entering a cell from the north (y = data->map.map_size)
    if (data->player.cell_y > data->map.map_size)
    {
        printf("You have entered a new cell from the north\n");
        data->player.cell_y = (data->player.cell_y - data->map.map_size);
        data->player.map_y++;
    }

    //entering a cell from the west (x = data->map.map_size)
    if (data->player.cell_x > data->map.map_size)
    {
        printf("You have entered a new cell from the west\n");
        printf("cell x before = %Lf\n", data->player.cell_x);
        data->player.cell_x = (data->player.cell_x - data->map.map_size);
        printf("cell x after = %Lf\n", data->player.cell_x);
        data->player.map_x++;
    }
    return (0);
}