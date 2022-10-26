#include "../cube.h"

/*void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.line_length + x * (data->mlx.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

int		display_ray(t_data *data, float pdx, float pdy)
{
	int len;

	len = 0;
	while (len < 20)
	{
		pdx = sin(data->player.angle) * len;
		pdy = cos(data->player.angle) * len;
		//my_mlx_pixel_put(data, data->player.x + pdx, data->player.y - pdy, 0x00FF0000);
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
	while (len < 20)
	{
		pdx = sin(data->player.angle) * len;
		pdy = cos(data->player.angle) * len;
		//my_mlx_pixel_put(data, data->player.x + pdx, data->player.y - pdy, 0);
		mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, data->player.x + pdx, data->player.y - pdy, 0);
		len++;
	}
	//mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 0, 0);
}