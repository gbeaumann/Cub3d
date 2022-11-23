#include "../cube.h"

void init_map_bis(t_data *data)
{
	data->map.map_height = data->map.map_size;
	data->map.map_width = data->map.map_size;
	data->map.game_display_x = 1280;
	data->map.game_display_y = 1024;
	data->map.game_display_start = 400;
}

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
	init_map_bis(data);
}