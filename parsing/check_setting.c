/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:30:21 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 10:03:05 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_char(char *tmp)
{
	if (tmp[0] != 'N' && tmp[0] != 'S'
		&& tmp[0] != 'E' && tmp[0] != 'W' && tmp[0] != 'C'
		&& tmp[0] != 'F' && tmp[0] != '1' && tmp[0] != '0')
	{
		printf("Error\nInvalid character found in file\n");
		if (tmp)
			free(tmp);
		return (1);
	}
	return (0);
}

static void	init_check_set(t_check_set *check_set)
{
	check_set->j = 0;
	check_set->color = 0;
	check_set->text = 0;
	check_set->tmp = NULL;
}

static int	check_param(t_check_set *check_set, t_data *data, char **params)
{
	check_set->tmp = parse_spaces(params[check_set->j], ' ');
	check_set->text = check_texture(data, check_set->tmp);
	check_set->color = init_color(check_set->tmp, data);
	if (check_char(check_set->tmp))
	{
		free_all(data);
		exit (1);
		return (1);
	}
	return (0);
}

static int	check_error_set(t_check_set *check_set, t_data *data)
{
	if (check_set->text != 4)
	{
		printf("Error\nInvalid number of textures\n");
		free_all(data);
		exit (1);
	}
	if (check_set->color != 2)
	{
		printf("Error\nWrong color settings\n");
		free_all(data);
		exit (1);
	}
	if (check_range(data) == 1)
	{
		free_all(data);
		exit(1);
	}
	return (0);
}

int	check_settings(t_data *data, char **params)
{
	t_check_set	check_set;

	init_check_set(&check_set);
	while (params[check_set.j])
	{
		check_param(&check_set, data, params);
		ft_free(check_set.tmp);
		check_set.j++;
	}
	check_error_set(&check_set, data);
	return (0);
}
