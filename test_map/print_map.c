#include	"../cube.h"

void	sprite(t_minimap *minimap, t_data *img, char type, int sprite_width, int sprite_height)
{
	printf("%c\n", type);
	if (type == '1')
		minimap->sprite = mlx_xpm_file_to_image(img->mlx,
			"./test_map/asset/sprites/wall.xpm", &minimap->sprite_width, &minimap->sprite_height);
	if (type == '0')
		minimap->sprite = mlx_xpm_file_to_image(img->mlx,
			"./test_map/asset/sprites/grid.xpm", &minimap->sprite_width, &minimap->sprite_height);
	mlx_put_image_to_window(img->mlx, img->mlx_win, minimap->sprite, sprite_width, sprite_height);
}

void	print_walls(t_minimap *minimap, t_data *img)
{
	int	sprite_width;
	int	sprite_height;
	int	map_width;
	int	map_height;

	sprite_width = 0;
	sprite_height = 0;
	map_width = 0;
	map_height = 0;
	while (map_height < minimap->map_height)
	{
		while (map_width < minimap->map_width)
		{
			sprite(minimap, img, minimap->map[map_height][map_width], sprite_width, sprite_height);
			map_width++;
			sprite_width += 60;
		}
		sprite_width = 0;
		sprite_height += 60;
		map_width = 0;
		map_height++;
	}
}