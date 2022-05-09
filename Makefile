NAME = so_long

SOURCES = main.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./libft/ft_split.c map_checker.c

CC = @gcc

OBJ = $(SRCS:.c=.o)

RM  = rm -rf

$(NAME): $(OBJ)
	gcc $(SOURCES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) *.o $(NAME)
