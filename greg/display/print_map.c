#include	"../cube.h"

void	sprite(t_data *data, char type, int sprite_width, int sprite_height)
{
	if (type == '1')
		data->map.sprite = mlx_xpm_file_to_image(data->mlx.mlx,
			"./get_map/asset/sprites/wall.xpm", &data->map.sprite_width, &data->map.sprite_height);
	if (type == '0')
		data->map.sprite = mlx_xpm_file_to_image(data->mlx.mlx,
			"./get_map/asset/sprites/grid.xpm", &data->map.sprite_width, &data->map.sprite_height);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->map.sprite, sprite_width, sprite_height);
}

void	print_walls(t_data *data)
{
	int	sprite_width;
	int	sprite_height;
	int	map_width;
	int	map_height;

	sprite_width = 0;
	sprite_height = 0;
	map_width = 0;
	map_height = 0;
	while (map_height < data->map.map_height)
	{
		while (map_width < data->map.map_width)
		{
			sprite(data, data->map.map[map_height][map_width], sprite_width, sprite_height);
			map_width++;
			sprite_width += 60;
		}
		sprite_width = 0;
		sprite_height += 60;
		map_width = 0;
		map_height++;
	}
}