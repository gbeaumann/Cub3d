#include	"cube.h"

int	ft_clic_close(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit (0);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	init_player(t_data *img, t_minimap *minimap)
{
	int	y;

	img->x = 450;
	img->y = 300;
	img->angle = 0;
	img->pdx = 0;
	img->pdy = 0;
	img->quarter = 1;
	y = img->y;
	while (y > img->y - 20)
	{
		mlx_pixel_put(img->mlx, img->mlx_win, img->x, y, 0x00FF0000);
		y--;
	}
	return (0);
}

int	player_move(int keycode, t_data *img, t_minimap *minimap)
{
	float	pdx;
	float	pdy;
	
	clear(img);
	if (keycode == 123)
		rotation_left(img, pdx, pdy);
	if (keycode == 124)
		rotation_right(img, pdx, pdy);
	if (keycode == 13)
		forward(img, pdx, pdy);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data				img;
	static t_read_map	gnl;
	t_minimap			minimap;
	char				*map_gnl;
	int					fd;
	
	// read map
	fd = open(argv[1], O_RDONLY);
	map_gnl = get_next_line(fd, &minimap, &gnl);
	printf("minimap height: %d\nminimap width: %d\n", minimap.map_width, minimap.map_height);

	// initialisation mlx
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, (minimap.map_width * 60), (minimap.map_height * 60), "Hello world!");
	img.img = mlx_new_image(img.mlx,  (minimap.map_width * 60), (minimap.map_height * 60));
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// minimap
	minimap.sprite_height = 15;
	minimap.sprite_width = 15;
	minimap.map = ft_split(map_gnl, '\n');
	print_walls(&minimap, &img);

	init_player(&img, &minimap);
	mlx_hook(img.mlx_win, 2, 0, player_move, &img);
	mlx_hook(img.mlx_win, 17, 1L << 5, ft_clic_close, &img);
	mlx_loop(img.mlx);
}
	