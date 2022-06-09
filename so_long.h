#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"

typedef struct list{
    int x;
    int y;
    int x1;
    int y1;
	int fd;
    void *img;
    void *mlx;
    void *win;
	char *map;
	char **whole_map;
	int line;
	int line_lenght;
	int player_x;
	int player_y;
	int coin;
	int coin_count;
	void *wall;
	void *grass;
	void *wall_path;
	void *grass_path;
	void *player_path;
	void *player;
	void *point_path;
	void *point;
	void *enemy_path;
	void *enemy;
	int step;
} t_list;

void map(t_list *list);
int map_to_str(t_list *list, char **argv);
void	xpm_to_image(t_list *list, char **argv);
//checks
void line_check(t_list *list);
void	ft_error(char *str);
//player moves
void player_up(t_list *list);
void player_down(t_list *list);
void player_right(t_list *list);
void player_left(t_list *list);
#endif