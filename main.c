#include	"cube.h"


int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;
	char	*map_gnl;

	// init map
	fd = open(argv[1], O_RDONLY);
	map_gnl = get_next_line(fd, &data);
	data.map.map = ft_split(map_gnl, '\n');
	//check error
	//check_map_errors(&data);
	// initialisation mlx
	data.mlx.mlx = mlx_init();
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, 1920, 1200, "Hello world!");
	data.mlx.img = mlx_new_image(data.mlx.mlx, data.map.game_display_x, data.map.game_display_y);
	data.mlx.addr = mlx_get_data_addr(data.mlx.img, &data.mlx.bits_per_pixel, &data.mlx.line_length, &data.mlx.endian);
	//print_walls(&data);
	print_mini_walls(&data);
	init_player(&data);
	//print_game(&data);

	mlx_hook(data.mlx.mlx_win, 2, 0, player_move, &data);
	mlx_hook(data.mlx.mlx_win, 17, 1L << 5, ft_clic_close, &data);
	mlx_loop(data.mlx.mlx);
	
}