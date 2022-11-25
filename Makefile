NAME =	cub3d
CC =	gcc
SRC =	main.c\
		init/init.c\
		init/init_len.c\
		init/init_map.c\
		init/init_pos.c\
		init/new_init_rays.c\
		init/get_sprites.c\
		parsing/check_setting.c\
		parsing/init_color.c\
		parsing/init_color_utils.c\
		parsing/parse_space.c\
		parsing/check_texture.c\
		parsing/check_texture_bis.c\
		parsing/parse_map.c\
		parsing/get_map.c\
		parsing/get_map_utils.c\
		parsing/parsing_utils.c\
		parsing/parsing_utils_2.c\
		get_map_greg/get_next_line.c\
		get_map_greg/get_next_line_utils.c\
		get_map_greg/check_map_errors.c\
		display/display.c\
		display/print_map.c\
		display/resize.c\
		display/get_color.c\
		display/get_small_color.c\
		display/test_pix_x.c\
		move/forward.c\
		move/backward.c\
		move/right.c\
		move/left.c\
		move/key_hook.c\
		move/rotation.c\
		move/player_location.c\
		check_move/check_right.c\
		check_move/check_left.c\
		check_move/check_forward.c\
		check_move/check_backward.c\
		check_move/map_check.c\
		check_move/wall_protect.c\
		ray/ray_len.c\
		ray/map_check_vert.c\
		ray/map_check_hor.c\
		ray/x_ray_length.c\
		ray/y_ray_length.c\
		ray/vert_dist.c\
		ray/hor_dist.c\
		ray/fix_fisheye.c\
		exit.c\
		
FLAGS =	-Wall -Werror -Wextra -g3 -fsanitize=address -fno-omit-frame-pointer
OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME) :	$(OBJ)
	make -C minilibix
	make -C libft
	$(CC) $(FALGS) $(SRC) minilibix/libmlx.a libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(NAME)

$(NAME) :	$(OBJ)
	make -C minilibix
	make -C libft
	$(CC) $(FALGS) $(SRC) minilibix/libmlx.a libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C minilibix
	make clean -C libft
	rm -f $(OBJ)
fclean: clean
	make clean -C minilibix
	make fclean	-C libft
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
