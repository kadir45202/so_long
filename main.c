/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:34:31 by kcetin            #+#    #+#             */
/*   Updated: 2022/06/08 23:40:38 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void xpm_to_image(t_list *list, t_img *img, char **argv)
{
	img->wall_path = "./img/wall.xpm";
	img->grass_path = "./img/grass.xpm";
	img->player_path = "./img/player.xpm";
	img->point_path = "./img/point.xpm";
	img->wall = mlx_xpm_file_to_image(list->mlx, img->wall_path, &list->x, &list->y);
	img->grass = mlx_xpm_file_to_image(list->mlx, img->grass_path, &list->x, &list->y);
	img->player = mlx_xpm_file_to_image(list->mlx, img->player_path, &list->x, &list->y);
	img->point = mlx_xpm_file_to_image(list->mlx, img->point_path, &list->x, &list->y);

	map(list, img, argv);
}

int ft_exit(int key)
{
	exit(0);
}

int keys(int key, t_list *list)
{
	if(key == 53 || key == 65307)
		{
		mlx_destroy_window(list->mlx, list->win);
		exit(0);
		}
	if(key == 13 || key == 119)
		{
		}
	printf("%i\n", key);
	return (0);
}


void map_control(t_list *list)
{
	int i = 0;
	int line = 0;
	while(list->whole_map[i] != NULL)
	{
		while(list->whole_map[i][line])
		{
			if(list->whole_map[i][line] == '1' || list->whole_map[i][line] == '2'
			|| list->whole_map[i][line] == '3' || list->whole_map[i][line] == '4')
			{
				line++;
			}
			else
			{
				printf("character error\n");
				exit(0);
			}
		}
		i++;
	}
}


int main(int agrc, char **argv)
{
	t_list *list = malloc(sizeof(t_list) * 10);
	t_img *img = malloc(sizeof(t_list) * 10);
    list->x1 = 0;
    list->y1 = 0;
    list->mlx = mlx_init();
	map_to_str(list, argv);
	//map_control(list);
	line_check(list);
    list->win = mlx_new_window(list->mlx, list->line_lenght * 32, list->line * 32, "./so_long");
	//printf("%d %d\n", list->line_lenght * 16, list->line * 16);

    xpm_to_image(list, img, argv);
	mlx_hook(list->win, 17, 0, ft_exit, 0);
	mlx_key_hook(list->win, keys, list);
    mlx_loop(list->mlx);
	free(list->whole_map);
	free(list);
	return 0;
}