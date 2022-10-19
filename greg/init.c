#include "cube.h"

int	init_player(t_data *img)
{
	int	y;

	img->cell_x = 30;
	img->cell_y = 30;
	//initialize cell x and y according to the size of the map
	//x = (number of pixel on x axis/ number of cells on the x axis (max i)) / 2
	//  -> where i is the greater index in x axis of the array where the map is stocked
	//		(max number of char per line)
	//y = (number of pixel on x axis/ number of cells on the x axis (max j)) / 2
	//  -> where j is the greater index of the array in terms of number of lines
	img->map_x = 7;
	img->map_y = 5;
	img->map = open_map("map1");
	printf("player: %c\n", img->map[img->map_y][img->map_x]);
	img->map_check_x = 0;
	img->map_check_y = 0;
	img->x = (img->map_x * 60) + img->cell_x;
	img->y = (img->map_y * 60) + img->cell_y;
	//initialize map_x, map_y according to the plyer's pos in the map (i, j);
	img->angle = 0;
	img->pdx = 0;
	img->pdy = 0;
	img->quarter = 1;
	img->ray_len = 0;
	img->ray_x = 0;
	img->ray_y = 0;
	y = img->y;
	while (y > img->y - 20)
	{
		my_mlx_pixel_put(img, img->x, y, 0x00FF0000);
		y--;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}