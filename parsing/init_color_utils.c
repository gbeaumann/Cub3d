/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:01:24 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 12:01:47 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../cube.h"

void	print_color_error(t_data *data, char *new, char *msg)
{
	printf("Error\nWrong color settings for the %s\n", msg);
	ft_free(new);
	free_all(data);
	exit (1);
}
