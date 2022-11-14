/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:51:01 by gbeauman          #+#    #+#             */
/*   Updated: 2022/10/25 16:11:51 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../cube.h"

void	map_empty(void)
{
	printf ("Error, the map is empty\n");
	exit (0);
}

void	dimention_finder(char *map_gnl, t_data *data)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = 0;
	height = 0;
	while (map_gnl[i])
	{
		if (map_gnl[i] == '\n')
		{
			height++;
			i++;
			width = 0;
		}
		i++;
		width++;
	}
	height++;
	data->map.map_width = width;
	data->map.map_height = height;
}

static int	init_read(int fd, t_data *data)
{
	data->gnl.fd = fd;
	data->gnl.pos = 0;
	data->gnl.max = read(fd, data->gnl.backup, BUFFER_SIZE);
	if (data->gnl.max <= 0)
		return (0);
	else
		return (1);
}

static char	check_read(t_data *data)
{
	char	resultat;

	if (data->gnl.pos >= data->gnl.max)
	{
		data->gnl.pos = 0;
		data->gnl.max = read(data->gnl.fd, data->gnl.backup, BUFFER_SIZE);
		if (data->gnl.max <= 0)
			return (0);
	}
	resultat = data->gnl.backup[data->gnl.pos];
	data->gnl.pos++;
	return (resultat);
}

static int	ft_len(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}

static char	*ft_join(char *str, char ch)
{
	char	*new_str;
	int		index;
	int		len;

	index = 0;
	len = ft_len(str);
	new_str = malloc((len + 2) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (index < len)
	{
		new_str[index] = str[index];
		index++;
	}
	new_str[index] = ch;
	new_str[index + 1] = '\0';
	if (str)
		free(str);
	return (new_str);
}

char	*get_next_line(int fd, t_data *data)
{
	char	ch;
	char	*str;
	int		index;
	int		height;

	index = 0;
	height = 0;
	str = NULL;
	if (data->gnl.fd != fd)
	{
		if (!init_read(fd, data))
			map_empty();
	}
	ch = check_read(data);
	while (ch)
	{
		if (ch == '\n')
			height++;
		str = ft_join(str, ch);
		ch = check_read(data);
	}
	dimention_finder(str, data);
	return (str);
}
