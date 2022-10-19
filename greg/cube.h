#ifndef		CUB3D_H
# define	CUB3D_H

# include	"./minilibix/mlx.h"
# include 	"get_next_line.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<math.h>
//# define		PI 3.141592653589793
# define		PI 3.141593

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	**map;
	long double	x;
	long double	y;
	long double cell_x;
	long double cell_y;
	int			map_x;
	int			map_y;
	long double close_x_v;
	long double close_y_v;
	long double close_x_h;
	long double close_y_h;
	void	*mlx;
	void	*mlx_win;
	long double	angle;
	long double tmp_angle;
	long double	pdx;
	long double	pdy;
	int		quarter;
	int		map_check_y;
	int		map_check_x;
	long double	ray_x;
	long double	ray_y;
	int		ray_len;
}				t_data;


int	main(void);

//display
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int		display_ray(t_data *img, float pdx, float pdy);
void	clear(t_data *img);
int		ft_clic_close(t_data *img);

char ** open_map(char *filename);

//initialization
int	init_player(t_data *img);

//movements and rotations
int	player_move(int keycode, t_data *img);
int	rotation_left(t_data *img, float pdx, float pdy);
int	rotation_right(t_data *img, float pdx, float pdy);
int	forward(t_data *img, float pdx, float pdy);
int backward(t_data *img, float pdx, float pdy);

int check_cell(t_data *img);
//int closest_intersection_x_y(t_data *img);
int	cal_x_dist(t_data *img);
int cal_y_dist(t_data *img);
int	cal_xaxis(t_data *img);
int check_map(t_data *img);
int check_x_axis_ray_length(t_data *img);
int forward_one_cell(t_data *img, float pdx, float pdy);

#endif