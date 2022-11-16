#ifndef		CUB3D_H
# define	CUB3D_H

# define	BUFFER_SIZE 10

# include	"./minilibix/mlx.h"
# include	"./libft/libft.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<math.h>
# include	<fcntl.h>
# define		PI 3.141593

typedef struct s_settings {

	char	*npath;
	char	*spath;
	char	*wpath;
	char	*epath;
	int		fr;
	int		fg;
	int		fb;
	int		cr;
	int		cg;
	int		cb;

}				t_settings;

typedef struct s_sprite
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_sprite;

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
	//sizes
	int		tab_size;
	int		line_size;
	int		max;
}		t_minimap;

typedef struct s_player {

	long double	x;
	long double	y;
	long double cell_x;
	long double cell_y;
	int			map_x;
	int			map_y;
}				t_player;

typedef struct s_ray {

	int		map_check_y;
	int		map_check_x;
	int		map_x;
	int		map_y;
	long double	ray_x;
	long double	ray_y;
	long double tmp_x;
	long double tmp_y;
	int		ray_len;
	//long double ray;
	long double angle;
	long double tmp_angle;
	long double init_tmp_angle;
	long double pdx;
	long double pdy;
	int  quarter;
	int	rot;
	char	wall;
}				t_ray;

typedef struct s_read_map
{
	char	backup[BUFFER_SIZE];
	int		pos;
	int		max;
	int		fd;
}			t_read_map;

typedef struct	s_data {
	
	t_settings	param;
	t_mlxinit	mlx;
	t_minimap	map;
	t_player	player;
	t_read_map	gnl;
	t_ray		ray[51];
	t_sprite	sprites[4];
	int			n;
	int			max;
}				t_data;

int	main(int argc, char **argv);

//display
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		display_ray(t_data *data, float pdx, float pdy);
void	clear(t_data *data);
int		ft_clic_close(t_data *data);
int fix_smooth(t_data *data, int ray);

//display game
void	print_game(t_data *data);
int fix_fish_eye(t_data *data);
int correct_perspective(t_data *data);
int test_pixel(t_data *data);
unsigned int    get_north_wall_pixel(t_data *data);
int	display_game(t_data *data);
int set_sprite(t_data *data);
int rule_of_three_y(int wall_heigth);

char ** open_map(char *filename);

//initialization
int		init_player(t_data *img);
int		find_pos(t_data *data);
void	init_map(t_data *data);
int		exception_len(t_data *data);
void    init_rays(t_data *data);

//parsing
int check_settings(t_data *data, char **params);
int init_color(char *info, t_data *data);
char *parse_spaces(char *toparse, char c);
int check_range(t_data *data);
int check_texture(t_data *data, char *param);
char    *ft_cpy_index(char *str, int i);
int check_path(char *path);
int get_map(char **tocheck, t_data *data);
int check_map_walls(t_data *data);
char    **ft_split_file(char *str, char c);

//utils
void    free_tab(char **tofree);

//movements and rotations
int	player_move(int keycode, t_data *data);
int	rotation_left(t_data *data);
int	rotation_right(t_data *data);
int	forward(t_data *data);
int backward(t_data *data);
int right(t_data *data);
int left(t_data *data);

//check movement (walls)
int check_right(t_data *data);
int check_left(t_data *data);
int check_forward(t_data *data);
int check_backward(t_data *data);
int set_check(t_data *data, long double tmpx, long double tmpy);

int check_cell(t_data *data);
int    cal_x_dist(t_data *data);
int cal_y_dist(t_data *data);
int check_vert_map(t_data *data);
int check_hor_map(t_data *data);
int check_map(t_data *data);
int x_ray_len_check(t_data *data);
int y_ray_len_check(t_data *data);
int forward_one_cell(t_data *data, float pdx, float pdy);
int find_ray_len(t_data *data);

int	quarter_calculation(t_data *data);

//map
char	*get_next_line(int fd, t_data *data);
void	check_map_errors(t_data *data);
void	print_walls(t_data *data);
void	print_mini_walls(t_data *data);

#endif
