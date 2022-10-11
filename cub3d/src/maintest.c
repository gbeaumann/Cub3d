#include "../mlx/mlx.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int     x;
    int     y;
    void	*mlx;
	void	*win;
}				t_data;

/*typedef struct	s_img {
	void	*mlx;
	void	*win;
}				t_img;*/


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_hook(int keycode, t_data *img)
{
    printf("adkjfhkjadfglkadjfg");
    if (keycode == 13)
    {
        printf("ca a hoookeee");
        img->y++;
        my_mlx_pixel_put(img, img->x, img->y, 0x00FF0000);
        return (0);
    }
    return (1);
}

int main (void) 
{
    t_data  img;
    
    img.x = 450;
    img.y = 300;
    printf("hello word\n");

    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, 900, 600, "lapin");
    img.img = mlx_new_image(img.mlx, 900, 600);    
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    my_mlx_pixel_put(&img, img.x, img.y, 0x00FF0000);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
    mlx_key_hook(img.win, key_hook, &img);
    mlx_loop(img.mlx);
    return (0);
}
