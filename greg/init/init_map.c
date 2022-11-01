#include "../cube.h"

void    init_map(t_data *data)
{
    int i;
	int	j;

	i = 0;
	j = 0;
    data->map.map_height = 60;
	data->map.map_width = 60;
	if (find_pos(data))
	{
		printf("Error in map\n");
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