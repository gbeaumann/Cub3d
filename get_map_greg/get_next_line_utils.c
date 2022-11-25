/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:58:32 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 15:59:31 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../cube.h"

void	map_empty(void)
{
	printf ("Error, the map is empty\n");
	exit (0);
}

void	dimention_finder(char *map_gnl, t_data *data)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = 0;
	height = 0;
	while (map_gnl[i])
	{
		if (map_gnl[i] == '\n')
		{
			height++;
			i++;
			width = 0;
		}
		i++;
		width++;
	}
	height++;
	data->map.map_width = width;
	data->map.map_height = height;
}
