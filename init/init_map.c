/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:11:31 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 14:11:59 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_map_bis(t_data *data)
{
	data->map.move_size = 2;
	data->map.map_size = 60;
	data->map.map_height = data->map.map_size;
	data->map.map_width = data->map.map_size;
	data->map.game_display_x = 845;
	data->map.game_display_y = 995;
	data->map.game_display_start = 0;
}

int	init_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (find_pos(data))
	{
		printf("Error\nInvalid number of players\n");
		free_all(data);
		exit (1);
	}
	while (data->map.map[j])
	{
		i = 0;
		while (data->map.map[j][i])
		{
			i++;
		}
		j++;
	}
	data->map.map_w = i - 1;
	data->map.map_h = j - 1;
	init_map_bis(data);
	return (0);
}
