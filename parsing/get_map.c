/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:14:12 by mchalard          #+#    #+#             */
/*   Updated: 2022/11/25 11:52:22 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	fill_spaces(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map.tab_size)
	{
		i = 0;
		while (i < data->map.line_size)
		{
			if (data->map.map[j][i] == ' ' || data->map.map[j][i] == '\n' ||
				data->map.map[j][i] == '\0')
				data->map.map[j][i] = '.';
			i++;
		}
		data->map.map[j][i] = '\0';
		j++;
	}
}

int	check_next_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != '\n' && line[i] != ' ')
			return (-1);
		i++;
	}
	return (i);
}

int	fill_map(char **tocheck, t_data *data)
{
	int	i;
	int	j;
	int	i2;

	i = 0;
	j = data->map.tab_size;
	data->map.map[j] = 0;
	j--;
	i = data->map.max;
	i2 = i - data->map.tab_size + 1;
	while (i >= i2)
	{
		ft_strlcpy(data->map.map[j], tocheck[i], ft_strlen(tocheck[i]) + 1);
		i--;
		j--;
	}
	fill_spaces(data);
	return (0);
}

void	ft_malloc_count_j(char **tocheck, t_mal_map *mal_map, t_data *data)
{
	while (tocheck[mal_map->j])
		mal_map->j++;
	mal_map->j--;
	data->map.max = mal_map->j;
}

int	get_map(char **tocheck, t_data *data)
{
	if (ft_mal_map(tocheck, data))
		return (1);
	fill_map(tocheck, data);
	if (check_map_walls(data))
	{
		printf("Error\nThe map is not surrounded by walls,\n");
		printf("the player is outside the map\n");
		printf("or there is a invalid character in map\n");
		free_all(data);
		exit (1);
	}
	return (0);
}
