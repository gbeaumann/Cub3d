#include "../cube.h"

int check_range(t_data *data)
{
    int count;

    count = 0;
    if (data->param.cb > 255 || data->param.cb < 0)
        count++;
    if (data->param.cg > 255 || data->param.cg < 0)
        count++;
    if (data->param.cr > 255 || data->param.cr < 0)
        count++;
    if (data->param.fb > 255 || data->param.fb < 0)
        count++;
    if (data->param.fg > 255 || data->param.fg < 0)
        count++;
    if (data->param.fr > 255 || data->param.fg < 0)
        count++;
    if (count > 0)
    {
        printf("Error\nWrong color range\n");
        return (1);
    }
    return (0);
}

int color_set(char **params)
{
    int i;
    int j;

    j = 0;
    while (params[j])
    {
        i = 0;
        while (params[j][i])
        {
            if (params[j][i] < 48 || params[j][i] > 57)
                return (1);
            i++;
        }
        j++;
    }
    if (j != 3)
        return (1);
    return (0);
}

int init_color_c(char *new, t_data *data)
{
    static int  countc = 0;
    char        **params;

    params = ft_split(new, ',');
    if (color_set(params) == 1)
    {
        free_tab(params);
        return (1);
    }
    data->param.cr = ft_atoi(params[0]);
    data->param.cg = ft_atoi(params[1]);
    data->param.cb = ft_atoi(params[2]);
    countc++;
    free_tab(params);
    if (countc > 1)
        return (1);
    return (0);
}

int init_color_f(char *new, t_data *data)
{
    static int  countf = 0;
    char        **params;

    params = ft_split(new, ',');
    if (color_set(params) == 1)
    {
        free_tab(params);
            return (1);
    }
    data->param.fr = ft_atoi(params[0]);
    data->param.fg = ft_atoi(params[1]);
    data->param.fb = ft_atoi(params[2]);
    countf++;
    free_tab(params);
    if (countf > 1)
        return (1);
    return (0);
}

int init_color(char *info, t_data *data)
{
    char        *new;

    new = NULL;
    if (info[0] == 'C')
    {
        new = parse_spaces(info, 'C');
        if (init_color_c(new, data))
        {
            printf("Error\nWrong color settings for the ceiling\n");
            free(new);
            return (1);
        }
        free(new);
    }
    if (info[0] == 'F')
    {
        new = parse_spaces(info, 'F');
        if (init_color_f(new, data))
        {
            printf("Error\nWrong color settings for the floor\n");
            free(new);
            return (1);
        }
        free(new);
    }
    return (0);
}

