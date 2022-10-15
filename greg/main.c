#include	"cube.h"

int	main(void)
{
	t_data	img;
	
	// initialisation mlx
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 900, 600, "Hello world!");
	img.img = mlx_new_image(img.mlx, 900, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	init_player(&img);
	mlx_hook(img.mlx_win, 2, 0, player_move, &img);
	mlx_hook(img.mlx_win, 17, 1L << 5, ft_clic_close, &img);
	mlx_loop(img.mlx);
}
	