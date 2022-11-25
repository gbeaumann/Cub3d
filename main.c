/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:27:20 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 13:43:28 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cube.h"

void	check_map_name(char *name)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	if (name[i - 1] != 'b' || name[i - 2] != 'u'
		|| name[i - 3] != 'c' || name[i - 4] != '.')
	{
		printf("Error\nWrong map name\n");
		exit (0);
	}
}

static int	free_setting(char *map_gnl, char **tofree)
{
	free_tab(tofree);
	ft_free(map_gnl);
	exit (1);
}

int	get_settings(char *file, t_data *data)
{
	int		fd;
	char	*map_gnl;
	char	**params;
	char	**mp_check;

	check_map_name(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCould not open map file\n");
		return (1);
	}
	map_gnl = get_next_line(fd, data);
	mp_check = ft_split_file(map_gnl, '\n');
	if (get_map(mp_check, data))
		free_setting(map_gnl, mp_check);
	free_tab(mp_check);
	params = ft_split(map_gnl, '\n');
	if (check_settings(data, params))
		free_setting(map_gnl, params);
	ft_free(map_gnl);
	free_tab(params);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("Invalid number of argument\n");
		return (1);
	}
	if (get_settings(argv[1], &data))
		return (1);
	data.map.small_map = 1;
	data.map.move_size = 10;
	data.map.map_size = 60;
	data.mlx.mlx = mlx_init();
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, 845, 995, "Cub3d");
	data.mlx.img = mlx_new_image(data.mlx.mlx, data.map.game_display_x, data.map.game_display_y);
	data.mlx.addr = mlx_get_data_addr(data.mlx.img, &data.mlx.bits_per_pixel, &data.mlx.line_length, &data.mlx.endian);
	init(&data);
	mlx_hook(data.mlx.mlx_win, 2, 0, key_press, &data);
	mlx_hook(data.mlx.mlx_win, 3, 0, key_release, &data);
	mlx_hook(data.mlx.mlx_win, 17, 1L << 5, ft_clic_close, &data);
	mlx_loop_hook(data.mlx.mlx, player_move, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
