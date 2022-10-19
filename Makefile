NAME =	cub3d
CC =	gcc
SRC =	rotata.c\
		keycode.c\
		quarter_rot.c\
		clear.c\
		./test_map/get_next_line.c\
		./test_map/print_map.c\
		
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
