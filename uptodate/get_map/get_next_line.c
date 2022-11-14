/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:08:47 by mchalard          #+#    #+#             */
/*   Updated: 2022/10/15 15:11:09 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

char	*ft_join(char *res, char *buffer)
{
	char	*tmp;

	if (!res)
		tmp = ft_strdup(buffer);
	else
		tmp = ft_strjoin(res, buffer);
	free(res);
	return (tmp);
}

char	*ft_newextra(char *extra)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (extra[i] && extra[i] != '\n')
		i++;
	if (!extra[i])
	{
		free(extra);
		return (NULL);
	}
	j = 0;
	i++;
	new = (char *) malloc((ft_strlen(extra) -i + 1) * sizeof(char));
	while (extra[i])
	{
		new[j++] = extra[i++];
	}
	new[j] = '\0';
	free(extra);
	return (new);
}

char	*ft_getline(char *res)
{
	char	*line;
	int		i;

	i = 0;
	if (!res[i])
		return (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	i = 0;
	while (res[i] && res[i] != '\n')
	{
		line[i] = res[i];
		i++;
	}
	if (res[i] && res[i] == '\n')
		line[i++] = '\n';
	line[i++] = '\0';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		a;

	a = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (a > 0)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[a] = '\0';
		res = ft_join(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	res = read_file(fd, res);
	if (!res)
		return (NULL);
	line = ft_getline(res);
	res = ft_newextra(res);
	return (line);
}
