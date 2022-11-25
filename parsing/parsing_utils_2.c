/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:19:47 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 13:24:15 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../cube.h"

void	init_split_f(t_split_f *split_f)
{
	split_f->i = 0;
	split_f->len = 0;
	split_f->start = 0;
	split_f->j = 0;
}

void	ft_split_file_bis(t_split_f *split_f, char c, char **tab, char *str)
{
	if (str[split_f->i] == c)
	{
		split_f->i++;
		tab[split_f->j] = ft_copy_line(str, split_f->start, split_f->i, c);
		split_f->start = split_f->i;
		split_f->j++;
	}
	else if (str[split_f->i + 1] == '\0')
	{
		split_f->i++;
		tab[split_f->j] = ft_copy_line(str, split_f->start, split_f->i, c);
		split_f->j++;
	}
	else
		split_f->i++;
}

//free tab
void	free_tab(char **tofree)
{
	int	j;

	j = 0;
	if (!tofree)
		return ;
	while (tofree[j])
	{
		free(tofree[j]);
		j++;
	}
	free(tofree);
}
