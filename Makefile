NAME =	so_long
CC =	gcc
SRC =	
FLAGS =	-Wall -Werror -Wextra -g3 -fsanitize=address -fno-omit-frame-pointer
OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME) :	$(OBJ)
	make -C minilibix
	make -C ft_printf
	make -C libft
	$(CC) $(FALGS) $(SRC) minilibix/libmlx.a ft_printf/libftprintf.a libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(NAME)

$(NAME) :	$(OBJ)
	make -C minilibix
	make -C ft_printf
	make -C libft
	$(CC) $(FALGS) $(SRC) minilibix/libmlx.a ft_printf/libftprintf.a libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C minilibix
	make clean -C ft_printf
	make clean -C libft
	rm -f $(OBJ)
fclean: clean
	make clean -C minilibix
	make fclean -C ft_printf
	make fclean	-C libft
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
