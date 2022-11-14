#include "../cube.h"

void    init_map(t_data *data)
{
    int i;
	int	j;

	i = 0;
	j = 0;
    data->map.map_height = data->map.map_size;
	data->map.map_width = data->map.map_size;
	if (find_pos(data))
	{
		printf("Error in map related to the position of the player\n");
		return ;
	}
	while (data->map.map[j])
	{
		i = 0;
		while (data->map.map[j][i])
		{
			i++;
		}
		j++;
	}
	data->map.map_w = i - 1;
	data->map.map_h = j - 1;
}