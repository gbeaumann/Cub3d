#ifndef		CUB3D_H
# define	CUB3D_H

# include	"./minilibix/mlx.h"
# include	"./libft/libft.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<math.h>
//open map
# include	<fcntl.h> 
# include	<unistd.h>

# define		PI 3.1415926535
# define	BUFFER_SIZE 10

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float	x;
	float	y;
	void	*mlx;
	void	*mlx_win;
	float	angle;
	float	pdx;
	float	pdy;
	int		quarter;
}				t_data;

typedef struct s_minimap
{
	int		map_height;
	int		map_width;
	char	**map;
	void	*sprite;
	int		sprite_height;
	int		sprite_width;
}		t_minimap;

typedef struct s_read_map
{
	char	backup[BUFFER_SIZE];
	int		pos;
	int		max;
	int		fd;
}			t_read_map;

int	main(int argc, char **argv);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int	rotation_left(t_data *img, float pdx, float pdy);
int	rotation_right(t_data *img, float pdx, float pdy);
int	forward(t_data *img, float pdx, float pdy);
int		quarter_1(t_data *img, float pdx, float pdy);
int		quarter_2(t_data *img, float pdx, float pdy);
int		quarter_3(t_data *img, float pdx, float pdy);
int		quarter_4(t_data *img, float pdx, float pdy);
void	clear(t_data *img);

// 2d map
char	*get_next_line(int fd, t_minimap *minimap, t_read_map *map_gnl);
void	print_walls(t_minimap *minimap, t_data *img);

#endif