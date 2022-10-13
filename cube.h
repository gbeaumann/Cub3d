#ifndef		CUB3D_H
# define	CUB3D_H

# include	"./minilibix/mlx.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<math.h>
# define		PI 3.1415926535

typedef struct	s_data {
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

int	main(void);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int	rotation_left(t_data *img, float pdx, float pdy);
int	rotation_right(t_data *img, float pdx, float pdy);
int	forward(t_data *img, float pdx, float pdy);
int		quarter_1(t_data *img, float pdx, float pdy);
int		quarter_2(t_data *img, float pdx, float pdy);
int		quarter_3(t_data *img, float pdx, float pdy);
int		quarter_4(t_data *img, float pdx, float pdy);
void	clear(t_data *img);

#endif