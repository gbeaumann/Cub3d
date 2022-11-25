/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:01:18 by gbeauman          #+#    #+#             */
/*   Updated: 2022/11/25 13:23:50 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

//parse the beggining of a string (ex: used in check texture to remove N or NO)
char	*ft_cpy_index(char *str, int i)
{
	int		i2;
	char	*new;

	i2 = 0;
	new = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	while (i < ft_strlen(str))
	{
		new[i2] = str[i];
		i2++;
		i++;
	}
	new[i2] = '\0';
	return (new);
}

//check path for texture
int	check_path(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY);
	if (fd == -1)
		return (1);
	else
		close (fd);
	return (0);
}

//ft_split keeping the separator
char	*ft_copy_line(char *str, int start, int i, char c)
{
	char	*cpy;
	int		i2;

	i2 = 0;
	cpy = ft_calloc((i - start) + 1, sizeof(char));
	while (start < i)
	{
		cpy[i2] = str[start];
		start++;
		i2++;
	}
	cpy[i2] = '\0';
	return (cpy);
}

void	print_map(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			printf("%c", map[j][i]);
			i++;
		}
		j++;
	}
}

char	**ft_split_file(char *str, char c)
{
	t_split_f	split_f;
	char		**tab;

	init_split_f(&split_f);
	while (str[split_f.i])
	{
		if (str[split_f.i] == c)
			split_f.len++;
		split_f.i++;
	}
	tab = ft_calloc(split_f.len + 2, sizeof(char *));
	split_f.i = 0;
	while (str[split_f.i])
		ft_split_file_bis(&split_f, c, tab, str);
	return (tab);
}
