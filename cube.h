#ifndef		CUB3D_H
# define	CUB3D_H

# define	BUFFER_SIZE 10

# include	"./minilibix/mlx.h"
# include	"./libft/libft.h"
//# include 	"get_next_line.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<math.h>
# include	<fcntl.h>
//# define		PI 3.141592653589793
# define		PI 3.141593

typedef struct s_mlxinit {

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}					t_mlxinit;

typedef struct s_minimap
{
	int		map_height;
	int		map_width;
	char	**map;
	void	*sprite;
	int		sprite_height;
	int		sprite_width;
	int		map_w;
	int		map_h;
	// print small or regular map
	int		small_map;
	int		map_size;
	int		move_size;
	// game display
	int		game_display_x;
	int		game_display_y;
	int		game_display_start;
}		t_minimap;

typedef struct s_player {

    long double    x;
    long double    y;
    long double cell_x;
    long double cell_y;
    int            map_x;
    int            map_y;
    long double    angle;
    int            rot;
    long double tmp_angle;
    long double    pdx;
    long double    pdy;
    int            quarter;
}                t_player;

typedef struct s_ray {

    int        map_check_y;
    int        map_check_x;
    long double    ray_x;
    long double    ray_y;
    long double tmp_x;
    long double tmp_y;
    int        ray_len;
    char    wall;
}                t_ray;

typedef struct s_read_map
{
	char	backup[BUFFER_SIZE];
	int		pos;
	int		max;
	int		fd;
}			t_read_map;

typedef struct	s_data {
	
	t_mlxinit	mlx;
	t_minimap	map;
	t_player	player;
	t_ray		ray;
	t_read_map	gnl;

}				t_data;


/*//void	*data;
	//char	*addr;
	//int		bits_per_pixel;
	//int		line_length;
	//int		endian;
	char	**map;
	//long double	x;
	//long double	y;
	//long double cell_x;
	//long double cell_y;
	//int			map_x;
	//int			map_y;
	//long double close_x_v;
	//long double close_y_v;
	//long double close_x_h;
	//long double close_y_h;
	//void	*mlx;
	//void	*mlx_win;
	//long double	angle;
	//long double tmp_angle;
	//long double	pdx;
	//long double	pdy;
	//int		quarter;
	int		map_check_y;
	int		map_check_x;
	long double	ray_x;
	long double	ray_y;
	int		ray_len;*/


int	main(int argc, char **argv);

//display
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		display_ray(t_data *data, float pdx, float pdy);
void	clear(t_data *data);
int		ft_clic_close(t_data *data);

//display game
void	print_game(t_data *data);

char ** open_map(char *filename);

//initialization
int	init_player(t_data *data);
int find_pos(t_data *data);
int exception_len(t_data *data);

//movements and rotations
int	player_move(int keycode, t_data *data);
int	rotation_left(t_data *data);
int	rotation_right(t_data *data);
int	forward(t_data *data);
int backward(t_data *data);

int check_cell(t_data *data);
//int closest_intersection_x_y(t_data *data);
int    cal_x_dist(t_data *data);
int cal_y_dist(t_data *data);
int check_vert_map(t_data *data);
int check_hor_map(t_data *data);
int check_map(t_data *data);
int x_ray_len_check(t_data *data);
int y_ray_len_check(t_data *data);
int forward_one_cell(t_data *data, float pdx, float pdy);
int find_ray_len(t_data *data);

//map
char	*get_next_line(int fd, t_data *data);
void	check_map_errors(t_data *data);
void	print_walls(t_data *data);
void	print_mini_walls(t_data *data);

#endif
