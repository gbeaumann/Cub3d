#include "../cube.h"

//parse the beggining of a string (ex: used in check texture to remove N or NO)
char    *ft_cpy_index(char *str, int i)
{
    int     i2;
    char   *new;

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
int check_path(char *path)
{
    int fd;

    if ((fd = open(path, O_WRONLY)) == -1)
        return (1);
    else
        close (fd);
    return (0);
}

//free tab
void    free_tab(char **tofree)
{
    int j;

    j = 0;
    while (tofree[j])
    {
        free(tofree[j]);
        j++;
    }
    free(tofree);
}


//ft_split keeping the separator
char    *ft_copy_line(char *str, int start, int i, char c)
{
    char *cpy;
    int i2;

    i2 = 0;
    cpy = malloc(sizeof(char) * (i - start) + 1);
    while (start < i)
    {
        cpy[i2] = str[start];
        start++;
        i2++;
    }
    cpy[i2] = '\0';
    return (cpy);
}


char    **ft_split_file(char *str, char c)
{
    int i;
    int len;
    int start;
    char **tab;
    int j;

    i = 0;
    len = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == c)
            len++;
        i++;
    }
    tab = malloc(sizeof(char *) * len + 2);
    i = 0;
    start = 0;
    while (str[i])
    {
        if (str[i] == c)
        {
            i++;
            tab[j] = ft_copy_line(str, start, i, c);
            start = i;
            j++;
        }
        else if (str[i + 1] == '\0')
        {
            i++;
            tab[j] = ft_copy_line(str, start, i, c);
            j++;
        } 
        else
            i++;
    }
    tab[j] = 0;
    return (tab);
}