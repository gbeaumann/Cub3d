#include "../libft/libft.h"
#include "../get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>



//lit le fichier map et stock le contenu dans un tableau de
// character et le renvoie
char **	read_map(int fd)
{
	char	*str;
	char	*result;
    char    **map;
	int		i;
	char	*tmp;

	result = ft_strdup("");
	i = 0;
	str = NULL;
	while (1)
	{
		tmp = result;
		str = get_next_line(fd);
		if (str != NULL)
			result = ft_strjoin(result, str);
		if (str == NULL)
			break ;
		free(tmp);
		free(str);
		i++;
	}
    map = ft_split(result, '\n');
	free(result);
    return (map);
}

void    display_map(char **map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            write(1, &map[y][x], 1);
            x++;
        }
        write(1, "\n", 1);
        y++;
    }
}

char ** open_map(char *filename)
{
    char    *path;
    int     fd;
    char ** map;

    path = ft_strjoin("map/", filename);
    if((fd = open(path, O_RDONLY)) < 0)
    {
        printf("Could not open file: %s\n", filename);
        return (NULL);
    }
    else
        printf ("File: %s succesfully opened\n", filename);
    ft_free(path);
    map = read_map(fd);
    display_map(map);
    close(fd);   
    return (map); 
}
