/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:34:31 by kcetin            #+#    #+#             */
/*   Updated: 2022/05/09 20:34:32 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int kapat(int key)
{
	exit(0);
}

int keys(int key, t_list *list)
{
	if(key == 53)
		exit(0);
	printf("%i\n", key);
	return (0);
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
	mlx_hook(list->win, 17, 0, kapat, 0);
	mlx_hook(list->win, 2, 0, keys, list);
    mlx_loop(list->mlx);
	return 0;
}