#include "../cube.h"

int    init_map(t_data *data)
{
    int i;
	int	j;

	i = 0;
	j = 0;
	data->map.map_height = data->map.map_size;
	data->map.map_width = data->map.map_size;
	if (find_pos(data))
	{
		printf("Error\nPosition of the player not found\n");
		return (1);
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
	return (0);
}