#include "../cube.h"

char *parse_spaces(char *toparse, char c)
{
    char    *parsed;
    int     size;
    int     i;
    int     inew;

    size = 0;
    i = 0;
    inew = 0;
    while (toparse[i])
    {
        if (toparse[i] != c)
            size++;
        i++;
    }
    parsed = malloc(sizeof(char) * size + 1);
    i = 0;
    while (toparse[i])
    {
        if (toparse[i] != c)
        {
            parsed[inew] = toparse[i];
            inew++;
        }
        i++;
    }
    parsed[inew] = '\0';
    return (parsed);
}


