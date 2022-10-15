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

int check_cell(t_data *img)
{
    printf("new check cell:\n");
    printf("cell_x: %Lf\n", img->cell_x);
    printf("cell_y: %Lf\n\n", img->cell_y);
    printf("map_y: %d\n", img->map_y);
    printf("map_x: %d\n", img->map_x);


    //entering a cell from the south (y = 0)
    if (img->cell_y < 0)
    {
        printf("You have entered a new cell from the south\n");
        img->cell_y = 60 - (img->cell_y * -1);
        img->map_y--;
    }

    //entering a cell from the east side (x = 0)
    if (img->cell_x < 0)
    {
        printf("You have entered a new cell from the East\n");
        img->cell_x = 60 - (img->cell_x * -1);
        img->map_x--;
    }

    //entering a cell from the north (y = 60)
    if (img->cell_y > 60)
    {
        printf("You have entered a new cell from the north\n");
        img->cell_y = (img->cell_y - 60);
        img->map_y++;
    }

    //entering a cell from the west (x = 60)
    if (img->cell_x > 60)
    {
        printf("You have entered a new cell from the west\n");
        img->cell_x = (img->cell_y - 60);
        img->map_x++;
    }
    return (0);
}