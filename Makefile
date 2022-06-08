NAME = so_long

SOURCES = main.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./libft/ft_split.c map_checker.c

CC = @gcc

OBJ = $(SRCS:.c=.o)

RM  = rm -rf

INC = mlx/libmlx_Linux.a

$(NAME): $(OBJ)
	$(CC) $(SOURCES) $(INC) -lX11 -lXext -lm -o $(NAME)

clean:
	$(RM) *.o $(NAME)

re:
	make clean
	make