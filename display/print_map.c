#include	"../cube.h"

void	sprite(t_data *data, char type, int sprite_width, int sprite_height)
{
	if (type == '1')
		data->map.sprite = mlx_xpm_file_to_image(data->mlx.mlx,
			"./get_map_greg/asset/sprites/wall.xpm", &data->map.sprite_width, &data->map.sprite_height);
	if (type == '0')
		data->map.sprite = mlx_xpm_file_to_image(data->mlx.mlx,
			"./get_map_greg/asset/sprites/grid.xpm", &data->map.sprite_width, &data->map.sprite_height);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->map.sprite, sprite_width, sprite_height);
}

void	print_walls(t_data *data)
{
	int	sprite_width;
	int	sprite_height;
	int	map_width;
	int	map_height;

	data->map.small_map = 1;
	data->map.move_size = 1;
	data->map.map_size = 60;
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

void	sprite_small(t_data *data, char type, int sprite_width, int sprite_height)
{
	if (type == '1')
		data->map.sprite = mlx_xpm_file_to_image(data->mlx.mlx,
			"./get_map_greg/asset/sprites/wall_15.xpm", &data->map.sprite_width, &data->map.sprite_height);
	if (type == '0')
		data->map.sprite = mlx_xpm_file_to_image(data->mlx.mlx,
			"./get_map_greg/asset/sprites/grid_15.xpm", &data->map.sprite_width, &data->map.sprite_height);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->map.sprite, sprite_width, sprite_height);
}

void	print_mini_walls(t_data *data)
{
	int	sprite_width;
	int	sprite_height;
	int	map_width;
	int	map_height;

	data->map.small_map = 4;
	data->map.move_size = 2;
	data->map.map_size = 15;
	sprite_width = 0;
	sprite_height = 0;
	map_width = 0;
	map_height = 0;
	while (map_height < data->map.map_height)
	{
		while (map_width < data->map.map_width)
		{
			sprite_small(data, data->map.map[map_height][map_width], sprite_width, sprite_height);
			map_width++;
			sprite_width += 15;
		}
		sprite_width = 0;
		sprite_height += 15;
		map_width = 0;
		map_height++;
	}
}

int	find_wall_ray_y1(t_data *data, int x, float proy, int trigger)
{
	unsigned int color;

	if (data->ray[data->n].wall == 'N')
		color = 0x00FF0000;
	else if (data->ray[data->n].wall == 'S')
		//color = 0xFFFF00;
		color = get_color_y1(data, proy, trigger, x);
	else if (data->ray[data->n].wall == 'E')
		color = 0x00FF00F0;
	else if (data->ray[data->n].wall == 'W')
		color = 0x00FFFFFF;
	return (color);
}

int	find_wall_ray_y2(t_data *data, int x, float proy, int trigger)
{
	unsigned int color;

	if (data->ray[data->n].wall == 'N')
		color = 0x00FF0000;
	else if (data->ray[data->n].wall == 'S')
		//color = 0xFFFF00;
		color = get_color_y2(data, proy, trigger, x);
	else if (data->ray[data->n].wall == 'E')
		color = 0x00FF00F0;
	else if (data->ray[data->n].wall == 'W')
		color = 0x00FFFFFF;
	return (color);
}

void	print_game(t_data *data)
{
	long double	wall_height;
	int len;
	int	ray_w;
	int y;
	int y2;
	int x;
	long double	ray;
	int	dif;
	static int  xn = 0;
	float		proy;
	static int xpix = 0;

	unsigned int	color_y1;
	unsigned int	color_y2;

	static int		trigger = 1;


	y2 = 0;
	ray = fix_fish_eye(data);
	len = 0;
	ray_w = 0;
	y = data->map.game_display_y / 2;
	y2 = data->map.game_display_y / 2;
	x = 10 * data->n;
	wall_height = (ray / (pow(ray, 2))) * 20000;
	proy = rule_of_three_y(wall_height);
	/*if (data->ray[data->n].wall == 'S')
		printf("proy[%d]: %f\n", data->n, proy);*/
	while (ray_w < 10)
	{
		if (trigger == 1)
		{
			xpix = get_xval_sprite(data, trigger);
			trigger = 0;
		}
		else
			xpix = get_xval_sprite(data, trigger);
		color_y1 = find_wall_ray_y1(data, x, proy, 1);
		color_y2 = find_wall_ray_y2(data, x, proy, 1);
		while (len < wall_height && len < 500)
		{
			my_mlx_pixel_put(data, x + ray_w, y + 1, color_y2);
			my_mlx_pixel_put(data, x + ray_w, y2, color_y1);
			color_y1 = find_wall_ray_y1(data, xpix, proy, 0);
			color_y2 = find_wall_ray_y2(data, xpix, proy, 0);
			y--;
			y2++;
			len++;
		}
		len = 0;
		y = data->map.game_display_y / 2;
		y2 = data->map.game_display_y / 2;
		ray_w++;
	}
	trigger = 1;
	//mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, data->map.game_display_start, 0);
}