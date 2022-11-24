#include "../cube.h"

int check_text_north(t_data *data, char *param)
{
    static int countn = 0;
    char   *path;

    countn++;
    if (param[0] == 'N' && param[1] == 'O')
        path = ft_cpy_index(param, 2);
    else if (param[0] == 'N')
        path = ft_cpy_index(param, 1);
    if (check_path(path) || countn > 1)
    {
        printf("Error\nInvalid path for north wall texture\n");
        free_all(data);
        exit (1);
    }
    data->param.npath = path;
    return (0);
}

int check_text_south(t_data *data, char *param)
{
    static int counts = 0;
    char   *path;

    counts++;
    if (param[0] == 'S' && param[1] == 'O')
        path = ft_cpy_index(param, 2);
    else if (param[0] == 'S')
        path = ft_cpy_index(param, 1);
    if (check_path(path) || counts > 1)
    {
        printf("Error\nInvalid path for south wall texture\n");
        free_all(data);
        exit (1);
    }
    data->param.spath = path;
    return (0);
}

int check_text_east(t_data *data, char *param)
{
    static int counte = 0;
    char   *path;

    counte++;
    if (param[0] == 'E' && param[1] == 'A')
        path = ft_cpy_index(param, 2);
    else if (param[0] == 'E')
        path = ft_cpy_index(param, 1);
    if (check_path(path) || counte > 1)
    {
        printf("Error\nInvalid path for east wall texture\n");
        free_all(data);
        exit (1);
    }
    data->param.epath = path;
    return (0);
}

int check_text_west(t_data *data, char *param)
{
    static int countw = 0;
    char   *path;

    countw++;
    if (param[0] == 'W' && param[1] == 'E')
        path = ft_cpy_index(param, 2);
    else if (param[0] == 'W')
        path = ft_cpy_index(param, 1);
    if (check_path(path) || countw > 1)
    {
        printf("Error\nInvalid path for west wall texture\n");
        free_all(data);
        exit (1);
    }
    data->param.wpath = path;
    return (0);
}

int check_texture(t_data *data, char *param)
{
    static int text = 0;

    if (param[0] == 'N' )
    {
        text++;
        if (check_text_north(data, param))
            return (1);
    }
    if (param[0] == 'S')
    {
        text++;
        if (check_text_south(data, param))
            return (1);
    }
    if (param[0] == 'E')
    {
        text++;
        if (check_text_east(data, param))
            return (1);
    }
    if (param[0] == 'W')
    {
        text++;
        if (check_text_west(data, param))
            return (1);
    }
    return (text);
}