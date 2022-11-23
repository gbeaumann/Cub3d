#include	"cube.h"

int	get_settings(char *file, t_data *data)
{
	int		fd;
	char	*map_gnl;
	char	**params;
	char	**mp_check;

	// init map
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCan't find file\n");
		return (1);
	}
	map_gnl = get_next_line(fd, data);
	mp_check = ft_split_file(map_gnl, '\n');
	if (get_map(mp_check, data))
	{
		free_tab(mp_check);
		free(map_gnl);
		return (1);
	}
	free_tab(mp_check);
	params = ft_split(map_gnl, '\n');
	if (check_settings(data, params))
	{
		free(map_gnl);
		free_tab(params);
		free_tab(data->map.map);
		return (1);
	}
	free(map_gnl);
	free_tab(params);
	return (0);
}

int	check_map_name(char *map)
{
	int	i;
	
	i = 0;
	while (map[i])
		i++;
	if (map[i - 1] != 'b' && map[i - 2] != 'u' && map[i - 3] != 'c')
		return (1);
	return (0);
}

int	check_error(t_data *data, int argc, char *map)
{
	if (argc != 2)
	{
		printf("Error\nInvalid number of argument\n");
		return (1);
	}
	if (get_settings(map, data))
		return (1);
	if (check_map_name(map))
	{
		printf("Error\nInvalid map name\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	//int		fd;
	//char	*map_gnl;

	/*if (argc != 2)
	{
		printf("Invalid number of argument\n");
		return (1);
	}
	if (get_settings(argv[1], &data))
		return (1);*/
	if (check_error(&data, argc, argv[1]))
		return (1);
	data.map.small_map = 1;
	data.map.move_size = 2;
	data.map.map_size = 60;

	// initialisation mlx
	data.mlx.mlx = mlx_init();
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, 910, 650, "Cub3D");
	data.mlx.img = mlx_new_image(data.mlx.mlx, data.map.game_display_x, data.map.game_display_y);
	data.mlx.addr = mlx_get_data_addr(data.mlx.img, &data.mlx.bits_per_pixel, &data.mlx.line_length, &data.mlx.endian);
	//print_walls(&data);
	//print_mini_walls(&data);
	if (init_player(&data))
		return (1);
	//test_pixel(&data);
	//print_game(&data);

	mlx_hook(data.mlx.mlx_win, 2, 0, key_press, &data);
	mlx_hook(data.mlx.mlx_win, 3, 0, key_release, &data);
	mlx_hook(data.mlx.mlx_win, 17, 1L << 5, ft_clic_close, &data);
	mlx_loop_hook(data.mlx.mlx, player_move, &data);
	mlx_loop(data.mlx.mlx);
}