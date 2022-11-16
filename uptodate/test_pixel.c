#include "cube.h"

//create a tab of data->sprites
//init the addr of each one according to the parth given in data
//find the proportion
//
//--> try: display one image

//set the texture for each side 
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

/*void	my_mlx_pixel_put_bis(t_sprite *data->sprites, int x)
{
	char	*dst;
    int     color;

	//dst = data->sprites[0].addr + (y * data->sprites[0].line_length + x * (data->sprites[0].bits_per_pixel / 8));
    dst = data->sprites[0].addr + (data->sprites[0].line_length + x * (data->sprites[0].bits_per_pixel / 8));
	*(unsigned int*)dst = color;
    printf("color: %d\n", color);
}*/


unsigned int get_color_tex(t_data *data, int x, int y)
{
    unsigned int	clr;
	int				t;
	int				r;
	int				g;
	int				b;

    clr = *(unsigned int *)(data->sprites[0].addr + (y * data->sprites[0].line_length + x * (data->sprites[0].bits_per_pixel / 8)));
	t = ((clr >> 24) & 0xFF);
	r = ((clr >> 16) & 0xFF);
	g = ((clr >> 8) & 0xFF);
	b = (clr & 0xFF);
	return (((t & 0xFF) << 24) + ((r & 0xFF) << 16)
		+ ((g & 0xFF) << 8) + (b & 0xFF));
}



unsigned int    get_north_wall_pixel(t_data *data)
{
    static int x = 0;
    static int y = 0;
    unsigned int color;
    static  int old_n = 0;

    if (data->n <= data->max/2 && x < 52)
    {
        if (x == 0)
            x = 26;
        if (data->n != old_n)
        {
            y = 0;
            x++;
        }
        printf("ray[%d]: n <= half x:========= %d\n", data->n, x);
        if (y < 52)
        {
            color = get_color_tex(data, x, y);
            y++;
        }
        old_n = data->n;
        //x++;
    }
    else if (data->n > data->max/2 && x > 0)
    {
        if (x >= 27)
            x = 27;
        if (data->n != old_n)
        {
            y = 0;
            x--;
        }
        printf("ray[%d]: n > half x:========= %d\n", data->n, x);
        while (y < 52)
        {
            color = get_color_tex(data, x, y);

            y++;
        }
        old_n = data->n;
    }
    return (color);
}

/*int test_pixel(t_data *data)
{
    t_sprite data->sprites[4];
    int      i;
    int      line_len;
    int      x;
    int         y;
    int     a;
    char    *pixel;
    unsigned int     color;

    x = 0;
    y = 0;
    set_data->sprites(data, data->sprites);
    printf("data->sprites[0]: line length = %d\n", data->sprites[0].line_length);
    printf("sprtes[0]: bpp = %d\n", data->sprites[0].bits_per_pixel );
    i = data->sprites[0].bits_per_pixel/8;
    line_len = 52 * i;
    a = 0;
    printf("addr: %s\n", data->sprites[0].addr);
    printf("line_len %d\n", line_len);
    while (y < 52)
    {
        x = 0;
        while (x < 52)
        {
            color = get_color_tex(data->sprites, x, y);
            my_mlx_pixel_put(data, x, y, color);
            x++;
        }
        y++;
    }
    //mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->mlx.img, 600, 300);
    //printf(sprite[0]: )
    return (0);
}*/