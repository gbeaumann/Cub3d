#include "cube.h"

int set_sprite(t_data *data)
{
    int test;

    test = 52;
    data->sprites[0].img = mlx_xpm_file_to_image(data->mlx.mlx, data->param.npath, &test, &test);
    if (data->sprites[0].img == NULL)
        printf("error sprite");
    data->sprites[0].addr = mlx_get_data_addr(data->sprites[0].img, &data->sprites[0].bits_per_pixel, &data->sprites[0].line_length, &data->sprites[0].endian);
    data->sprites[1].img = mlx_xpm_file_to_image(data->mlx.mlx, data->param.spath, &test, &test);
    data->sprites[1].addr = mlx_get_data_addr(data->sprites[1].img, &data->sprites[1].bits_per_pixel, &data->sprites[1].line_length, &data->sprites[1].endian);
    data->sprites[2].img = mlx_xpm_file_to_image(data->mlx.mlx, data->param.epath, &test, &test);
    data->sprites[2].addr = mlx_get_data_addr(data->sprites[2].img, &data->sprites[2].bits_per_pixel, &data->sprites[2].line_length, &data->sprites[2].endian);
    data->sprites[3].img = mlx_xpm_file_to_image(data->mlx.mlx, data->param.wpath, &test, &test);
    data->sprites[3].addr = mlx_get_data_addr(data->sprites[3].img, &data->sprites[3].bits_per_pixel, &data->sprites[3].line_length, &data->sprites[3].endian);
    return (0);
}


unsigned int get_color_tex(t_data *data, int x, int y, int s)
{
    unsigned int	clr;
	int				t;
	int				r;
	int				g;
	int				b;

    clr = *(unsigned int *)(data->sprites[s].addr + (y * data->sprites[s].line_length + x * (data->sprites[s].bits_per_pixel / 8)));
	t = ((clr >> 24) & 0xFF);
	r = ((clr >> 16) & 0xFF);
	g = ((clr >> 8) & 0xFF);
	b = (clr & 0xFF);
	return (((t & 0xFF) << 24) + ((r & 0xFF) << 16)
		+ ((g & 0xFF) << 8) + (b & 0xFF));
}

