#include "../cube.h"


//------> if we know where we are in a cell we know when we change to another one
//------> increment or decrement the position x y in term of cell coordinate
// when we ennter a new cell to know if where we are in the map ( the x and y 
//correspond to the i and j where the the map is stocked)
//------> check when do we want it to be the limit of a cell ( 0 or < 0 ) =====????
//------> calculate before moving if it is possible to move there;
//------> Should we calculate pixel per pixel ( 5 right now)  for each move to not go 
//through walls ex: angles =====????

//map_y => y coordinate of the player position in map;
//map_x => x coordinate of the player position in map;

int check_cell(t_data *data)
{
    //entering a cell from the south (y = 0)
    if (data->player.cell_y < 0)
    {
        printf("You have entered a new cell from the south\n");
        data->player.cell_y = 60 - (data->player.cell_y * -1);
        data->player.map_y--;
    }

    //entering a cell from the east side (x = 0)
    if (data->player.cell_x < 0)
    {
        printf("You have entered a new cell from the East\n");
        data->player.cell_x = 60 - (data->player.cell_x * -1);
        data->player.map_x--;
    }

    //entering a cell from the north (y = 60)
    if (data->player.cell_y > 60)
    {
        printf("You have entered a new cell from the north\n");
        data->player.cell_y = (data->player.cell_y - 60);
        data->player.map_y++;
    }

    //entering a cell from the west (x = 60)
    if (data->player.cell_x > 60)
    {
        printf("You have entered a new cell from the west\n");
        data->player.cell_x = (data->player.cell_y - 60);
        data->player.map_x++;
    }
    return (0);
}