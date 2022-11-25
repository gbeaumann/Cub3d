
#include "cube.h"


void ft_free(char *str)
{
    if (str)
        free(str);
}

int free_all(t_data *data)
{
    ft_free(data->param.npath);
    ft_free(data->param.spath);
    ft_free(data->param.wpath);
    ft_free(data->param.epath);
    free_tab(data->map.map);
    return (0);
}

