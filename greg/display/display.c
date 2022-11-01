#include "../cube.h"

int		display_ray(t_data *data, float pdx, float pdy)
{
	int len;

	len = 0;
	data->n = 0;
	while (data->n < data->max)
	{
		len = 0;
		find_ray_len(data);
		while (len < data->ray[data->n].ray_len)
		{
			pdx = sin(data->ray[data->n].angle) * len;
			pdy = cos(data->ray[data->n].angle) * len;
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, data->player.x + pdx, data->player.y - pdy, 0x00FF0000);
			len++;
		}
		data->ray[data->n].pdx = pdx;
		data->ray[data->n].pdy = pdy;
		data->n++;
	}
	return (0);
}

void	clear(t_data *data)
{
	int		len;
	float	pdx;
	float	pdy;

	len = 0;
	data->n = 0;
	while (data->n < data->max)
	{
		len = 0;
		pdx = data->ray[data->n].pdx;
		pdy = data->ray[data->n].pdy;
		while (len < data->ray[data->n].ray_len)
		{
			pdx = sin(data->ray[data->n].angle) * len;
			pdy = cos(data->ray[data->n].angle) * len;
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, data->player.x + pdx, data->player.y - pdy, 0);
			len++;
		}
		data->n++;
	}
}