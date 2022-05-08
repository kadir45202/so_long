#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "./gnl/get_next_line.h"

typedef struct list{
    int x;
    int y;
    int x1;
    int y1;
	int fd;
    void *img;
    void *mlx;
    void *win;
} t_list;

typedef struct img{
	void *wall;
	void *grass;
	void *wall_path;
	void *grass_path;
	void *player_path;
	void *player;
	void *point_path;
	void *point;
	
} t_img;
#endif