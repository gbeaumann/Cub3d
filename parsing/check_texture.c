/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:27:24 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 10:29:23 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_texture(t_data *data, char *param)
{
	static int	text = 0;
	int			nbr_text;

	nbr_text = 0;
	text += check_texture_bis(data, param, nbr_text);
	return (text);
}