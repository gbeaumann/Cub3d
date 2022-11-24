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
    int text;
    int color;

    j = 0;
    color = 0;
    text = 0;
    while ( params[j])
    {
        tmp = parse_spaces(params[j], ' ');
        text = check_texture(data, tmp);
        color = init_color(tmp, data);
        if (check_char(tmp))
        {
            free_all(data);
            exit (1);
            return(1);
        }
        ft_free(tmp);
        j++;
    }
    if (text != 4)
    {
        printf("Error\nInvalid number of textures\n");
        free_all(data);
        exit (1);
    }
    if (color != 2)
    {
        printf("Error\nWrong color settings\n");
        free_all(data);
        exit (1);
    }
    if (check_range(data) == 1)
    {
        free_all(data);
        exit(1);
    }
    return (0);
}