/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:56:10 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 15:57:15 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../cube.h"

static int	check_around_ground(t_data *data, int i, int j)
{
	if (data->map.map[i][j - 1] != '1' && data->map.map[i][j - 1] != '0')
		return (0);
	if (data->map.map[i][j + 1] != '1' && data->map.map[i][j + 1] != '0')
		return (0);
	if (data->map.map[i - 1][j] != '1' && data->map.map[i - 1][j] != '0')
		return (0);
	if (data->map.map[i + 1][j] != '1' && data->map.map[i + 1][j] != '0')
		return (0);
	return (1);
}

static void	print_error(int type)
{
	if (type == 1)
	{
		printf("Error\nHole in the walls\n");
		exit (0);
	}
	if (type == 2)
	{
		printf("Error\nMalloc\n");
		exit (0);
	}
}

static void	check_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j])
			j++;
		if (j > data->map.map_width)
			data->map.map_width = j;
		j = 0;
		i++;
	}
	data->map.map_height = i;
}

static void	fill_map_void(t_data *data)
{
	char	*str_map_empty;
	char	**stock_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str_map_empty = (char *)malloc(((data->map.map_height * data->map.map_width)
				+ 1) * sizeof(char));
	if (!str_map_empty)
		print_error(2);
	while (i < ((data->map.map_height * data->map.map_width)))
	{
		str_map_empty[i] = '1';
		i++;
	}
	i = 1;
	while (str_map_empty[i])
	{
		if (i % data->map.map_width == 0)
			str_map_empty[i] = '\n';
		i++;
	}
	str_map_empty[i] = '\0';
}

void	check_map_errors(t_data *data)
{
	check_wall(data);
	fill_map_void(data);
}
