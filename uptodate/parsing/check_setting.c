#include "../cube.h"

int check_char(char *tmp)
{
    if (tmp[0] != 'N' && tmp[0] != 'S' 
            && tmp[0] != 'E' && tmp[0] != 'W' && tmp[0] != 'C' && 
            tmp[0] != 'F' && tmp[0] != '1' && tmp[0] != '0')
    {
        printf("Error\nInvalid character found in file\n");
        if (tmp)
            free(tmp);
        return (1);
    }
    return (0);
}

int check_settings(t_data *data, char **params)
{
    int j;
    char *tmp;

    j = 0;
    while ( params[j])
    {
        tmp = parse_spaces(params[j], ' ');
        if(check_texture(data, tmp))
            return (1);
        else if (init_color(tmp, data))
            return (1);
        else
        {
            if (check_char(tmp))
                return(1);
        }
        if (tmp)
            free(tmp);
        j++;
    }
    if (check_range(data) == 1)
        return (1);
    return (0);
}