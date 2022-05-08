# include "./mlx/mlx.h"
# include "so_long.h"

void xpm_to_image(t_list *list, t_img *img)
{
	img->wall_path = "./img/wall.xpm";
	img->grass_path = "./img/grass.xpm";
	img->player_path = "./img/player.xpm";
	img->point_path = "./img/point.xpm";
	img->wall = mlx_xpm_file_to_image(list->mlx, img->wall_path, &list->x, &list->y);
	img->grass = mlx_xpm_file_to_image(list->mlx, img->grass_path, &list->x, &list->y);
	img->player = mlx_xpm_file_to_image(list->mlx, img->player_path, &list->x, &list->y);
	img->point = mlx_xpm_file_to_image(list->mlx, img->point_path, &list->x, &list->y);
}

void map(t_list *list, t_img *img)
{
	int i = -1;
	list->fd = open("./maps/map.ber", O_RDONLY);
	char *str;
	str = malloc(sizeof(str) * 1000);
	read(list->fd, str, 110);
	while(str[i++] != '9')
	{
		if(str[i] == '1')
			mlx_put_image_to_window(list->mlx, list->win, img->wall, list->x1, list->y1);
		if(str[i] == '2')
			mlx_put_image_to_window(list->mlx, list->win, img->grass, list->x1, list->y1);
		if(str[i] == '3')
			mlx_put_image_to_window(list->mlx, list->win, img->player, list->x1, list->y1);
		if(str[i] == '4')
			mlx_put_image_to_window(list->mlx, list->win, img->point, list->x1, list->y1);
		list->x1 += 32;
		if(str[i] == '\n')
		{
			list->x1 = 0;
			list->y1 += 32;
		}
	}
	free(str);
}

int main()
{
	t_list *list = malloc(sizeof(t_list) * 10);
	t_img *img = malloc(sizeof(t_list) * 10);
    list->x1 = 0;
    list->y1 = 0;
    list->mlx = mlx_init();
    list->win = mlx_new_window(list->mlx, 320, 320, "chess");
    xpm_to_image(list, img);
	map(list, img);
	free(list);
    mlx_loop(list->mlx);
}

