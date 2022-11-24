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


int	find_wall_ray_y1(t_data *data, int x, float proy, int trigger)
{
	unsigned int color;

	if (data->ray[data->n].wall == 'N')
		color = get_color_y1(data, proy, trigger, x, 1);
	else if (data->ray[data->n].wall == 'S')
		color = get_color_y1(data, proy, trigger, x, 0);
	else if (data->ray[data->n].wall == 'E')
		color = get_color_y1(data, proy, trigger, x, 2);
	else if (data->ray[data->n].wall == 'W')
		color = get_color_y1(data, proy, trigger, x, 3);
	return (color);
}

int	find_wall_ray_y2(t_data *data, int x, float proy, int trigger)
{
	unsigned int color;

	if (data->ray[data->n].wall == 'N')
		color = get_color_y2(data, proy, trigger, x, 1);
	else if (data->ray[data->n].wall == 'S')
		color = get_color_y2(data, proy, trigger, x, 0);
	else if (data->ray[data->n].wall == 'E')
		color = get_color_y2(data, proy, trigger, x, 2);
	else if (data->ray[data->n].wall == 'W')
		color = get_color_y2(data, proy, trigger, x, 3);
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
	float		proy;
	static int xpix = 0;

	unsigned int	color_y1;
	unsigned int	color_y2;

	y2 = 0;
	ray = fix_fish_eye(data);
	len = 0;
	ray_w = 0;
	y = data->map.game_display_y / 2;
	y2 = data->map.game_display_y / 2;
	x = 6 * data->n;
	wall_height = (ray / (pow(ray, 2))) * 20000;
	proy = rule_of_three_y(wall_height);
	xpix = find_x_pix(data);
	while (ray_w < 6)
	{
		color_y1 = find_wall_ray_y1(data, x, proy, 1);
		color_y2 = find_wall_ray_y2(data, x, proy, 1);
		while (len < wall_height && len < 498)
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
}