#include "../cube.h"

int		display_ray(t_data *data, float pdx, float pdy)
{
	int len;

	len = 0;
	find_ray_len(data);
	while (len < data->ray.ray_len)
	{
		pdx = sin(data->player.angle) * len;
		pdy = cos(data->player.angle) * len;
		mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, data->player.x + pdx, data->player.y - pdy, 0x00FF0000);
		len++;
	}
	data->player.pdx = pdx;
	data->player.pdy = pdy;
	return (0);
}

void	clear(t_data *data)
{
	int		len;
	float	pdx;
	float	pdy;

	len = 0;
	pdx = data->player.pdx;
	pdy = data->player.pdy;
	while (len < data->ray.ray_len)
	{
		pdx = sin(data->player.angle) * len;
		pdy = cos(data->player.angle) * len;
		mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, data->player.x + pdx, data->player.y - pdy, 0);
		len++;
	}
	//mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
}