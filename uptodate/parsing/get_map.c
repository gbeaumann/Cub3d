/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:14:12 by mchalard          #+#    #+#             */
/*   Updated: 2022/11/23 14:14:15 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void    fill_spaces(t_data *data)
{
    int i;
    int j;

    j = 0;
    while (j < data->map.tab_size)
    {
        i = 0;
        while (i < data->map.line_size)
        {
            if (data->map.map[j][i] != '0' && data->map.map[j][i] != '1' &&
            data->map.map[j][i] != 'N' && data->map.map[j][i] != 'S' && 
            data->map.map[j][i] != 'E' && data->map.map[j][i] != 'W')
                data->map.map[j][i] = '.';
            i++;
        }
        data->map.map[j][i] = '\0';
        j++;
    }
}

int check_next_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '0' && line[i] != '1' && line[i] != 'N' 
        && line[i] != 'S' && line[i] != 'E' && line[i] != 'W' 
        && line[i] != '\n' && line[i] != ' ')
            return (-1);
        i++;
    }
    return (i);
}

int fill_map(char **tocheck, t_data *data)
{
    int i;
    int j;
    int i2;

    i = 0;
    j = data->map.tab_size;
    data->map.map[j] = 0;
    j--;
    i = data->map.max;
    i2 = i - data->map.tab_size + 1;
    while (i >= i2)
    {
        ft_strlcpy(data->map.map[j], tocheck[i], ft_strlen(tocheck[i]) + 1);
        i--;
        j--;
    }
    fill_spaces(data);
    return (0);
}

int    ft_malloc_map(char **tocheck, t_data *data)
{
    int j;
    int tab_size;
    int max_size;
    int line_size;

    j = 0;
    tab_size = 0;
    max_size = 0;
    line_size = 0;
    while (tocheck[j])
        j++;
    j--;
    data->map.max = j;
    while (j > 0)
    {
        line_size = check_next_line(tocheck[j]);
        if (line_size < 0)
        {
            if (j == data->map.max)
            {
                printf("Error\nInvalid line in file\n");
                return (1);
            }
            break;
        }
        else if (line_size > max_size)
            max_size = line_size;
        j--;
        tab_size++;
    }
    data->map.map = ft_calloc(tab_size + 1, sizeof(char *));
    j = 0;
    while (j < tab_size)
    {
        data->map.map[j] = ft_calloc(max_size + 1, sizeof(char));
        j++;
    }
    data->map.tab_size = tab_size;
    data->map.line_size = max_size;
    return (0);
}

int get_map(char **tocheck, t_data *data)
{
    if (ft_malloc_map(tocheck, data))
        return (1);
    fill_map(tocheck, data);
    if (check_map_walls(data))
    {
        printf("Error\nThe map is not surrounded by walls\n");
        return (1);
    }
    return (0);
}