/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:45:52 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 11:50:20 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../cube.h"

void	init_mal_map(t_mal_map *mal_map)
{
	mal_map->j = 0;
	mal_map->tab_size = 0;
	mal_map->msize = 0;
	mal_map->line_size = 0;
}

int	ft_mal_map_bis(char **tocheck, t_data *data, t_mal_map *mal_map)
{
	mal_map->line_size = check_next_line(tocheck[mal_map->j]);
	if (mal_map->line_size < 0)
	{
		if (mal_map->j == data->map.max)
		{
			printf("Error\nInvalid line in file\n");
			return (1);
		}
		return (2);
	}
	else if (mal_map->line_size > mal_map->msize)
		mal_map->msize = mal_map->line_size;
	return (0);
}

int	ft_mal_map(char **tocheck, t_data *data)
{
	t_mal_map	mal_map;
	int			trigger;

	init_mal_map(&mal_map);
	ft_malloc_count_j(tocheck, &mal_map, data);
	while (mal_map.j > 0)
	{
		trigger = ft_mal_map_bis(tocheck, data, &mal_map);
		if (trigger == 1)
			return (1);
		if (trigger == 2)
			break ;
		mal_map.j--;
		mal_map.tab_size++;
	}
	data->map.map = ft_calloc(mal_map.tab_size + 1, sizeof(char *));
	mal_map.j = 0;
	while (mal_map.j < mal_map.tab_size)
	{
		data->map.map[mal_map.j] = ft_calloc(mal_map.msize + 1, sizeof(char));
		mal_map.j++;
	}
	data->map.tab_size = mal_map.tab_size;
	data->map.line_size = mal_map.msize;
	return (0);
}
