/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:09:48 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 12:18:33 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void	init_parse_sp(t_parse_sp *parse_sp)
{
	parse_sp->size = 0;
	parse_sp->i = 0;
	parse_sp->inew = 0;
}

char	*parse_spaces(char *toparse, char c)
{
	t_parse_sp	parse_sp;
	char		*parsed;

	init_parse_sp(&parse_sp);
	while (toparse[parse_sp.i])
	{
		if (toparse[parse_sp.i] != c)
			parse_sp.size++;
		parse_sp.i++;
	}
	parsed = malloc(sizeof(char) * parse_sp.size + 1);
	parse_sp.i = 0;
	while (toparse[parse_sp.i])
	{
		if (toparse[parse_sp.i] != c)
		{
			parsed[parse_sp.inew] = toparse[parse_sp.i];
			parse_sp.inew++;
		}
		parse_sp.i++;
	}
	parsed[parse_sp.inew] = '\0';
	return (parsed);
}
