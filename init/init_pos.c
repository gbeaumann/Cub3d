/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:53:21 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 14:05:56 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	dir_n(t_data *data)
{
	data->ray[data->ray1].wall = 'S';
	data->ray[data->ray1].angle = 0;
	data->ray[data->ray1].rot = 0;
	data->ray[data->ray1].quarter = 1;
	return (1);
}

int	dir_e(t_data *data)
{
	data->ray[data->ray1].wall = 'W';
	data->ray[data->ray1].angle = PI / 2;
	data->ray[data->ray1].rot = 4;
	data->ray[data->ray1].quarter = 2;
	return (1);
}

int	init_angle_first_ray(char dir, t_data *data)
{
	static char	count = 0;

	if (dir == 'N')
		count += dir_n(data);
	else if (dir == 'E')
		count += dir_e(data);
	else if (dir == 'S')
	{
		data->ray[data->ray1].wall = 'N';
		data->ray[data->ray1].angle = PI;
		data->ray[data->ray1].rot = 8;
		data->ray[data->ray1].quarter = 3;
		count++;
	}
	else if (dir == 'W')
	{
		data->ray[data->ray1].wall = 'E';
		data->ray[data->ray1].angle = 3 * (PI / 2);
		data->ray[data->ray1].rot = 12;
		data->ray[data->ray1].quarter = 4;
		count++;
	}
	return (count);
}

void	init_find_p(t_find_p *f_p)
{
	f_p->i = 0;
	f_p->j = 0;
	f_p->p = 0;
}

int	find_pos(t_data *data)
{
	t_find_p	f_p;

	init_find_p(&f_p);
	while (data->map.map[f_p.j])
	{
		f_p.i = 0;
		while (data->map.map[f_p.j][f_p.i])
		{
			f_p.p = init_angle_first_ray(data->map.map[f_p.j][f_p.i], data);
			if (data->map.map[f_p.j][f_p.i] != '0'
			&& data->map.map[f_p.j][f_p.i] != '1'
			&& data->map.map[f_p.j][f_p.i] != '.')
			{
				data->map.map[f_p.j][f_p.i] = '0';
				data->player.map_x = f_p.i;
				data->player.map_y = f_p.j;
			}
			f_p.i++;
		}
		f_p.j++;
	}
	if (f_p.p != 1)
		return (1);
	return (0);
}
