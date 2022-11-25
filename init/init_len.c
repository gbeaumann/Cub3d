/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:49:33 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 13:50:28 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	find_south_wall(t_data *data)
{
	int	y;

	y = data->player.map_y;
	while (data->map.map[y][data->player.map_x] != '1')
		y--;
	data->ray[data->n].ray_len = ((data->player.map_y - 1 - y) * data->map.map_size) + data->player.cell_y;
	data->ray[data->n].wall = 'S';
	data->ray[data->n].imgx = data->player.cell_x;
	return (0);
}

int	find_west_wall(t_data *data)
{
	int	x;

	x = data->player.map_x;
	while (data->map.map[data->player.map_y][x] != '1')
		x++;
	data->ray[data->n].ray_len = ((x - data->player.map_x - 1) * data->map.map_size) + (data->map.map_size - data->player.cell_x);
	data->ray[data->n].wall = 'W';
	data->ray[data->n].imgy = data->player.cell_y;
	return (0);
}

int	find_north_wall(t_data *data)
{
	int	y;

	y = data->player.map_y;
	while (data->map.map[y][data->player.map_x] != '1')
		y++;
	data->ray[data->n].ray_len = ((y - data->player.map_y - 1) * data->map.map_size) + (data->map.map_size - data->player.cell_y);
	data->ray[data->n].wall = 'N';
	data->ray[data->n].imgx = data->player.cell_x;
	return (0);
}

int	find_east_wall(t_data *data)
{
	int	x;

	x = data->player.map_x;
	while (data->map.map[data->player.map_y][x] != '1')
		x--;
	data->ray[data->n].ray_len = ((data->player.map_x - 1 - x) * data->map.map_size) + (data->player.cell_x);
	data->ray[data->n].wall = 'E';
	data->ray[data->n].imgy = data->player.cell_y;
	return (0);
}

int	exception_len(t_data *data)
{
	if (data->ray[data->n].angle == 0 || data->ray[data->n].angle == (2 * PI))
		find_south_wall(data);
	else if (data->ray[data->n].angle == PI / 2)
		find_west_wall(data);
	else if (data->ray[data->n].angle == PI)
		find_north_wall(data);
	else if (data->ray[data->n].angle == (3 * (PI / 2)))
		find_east_wall(data);
	else
		return (1);
	return (0);
}
