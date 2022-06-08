/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:05:03 by kcetin            #+#    #+#             */
/*   Updated: 2022/06/08 23:24:59 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int map_to_str(t_list *list, char **argv)
{
	int i;
	i = 0;
	list->fd = open(argv[1], O_RDONLY);
	list->map = malloc(sizeof(list->map) * 1000);
	i = read(list->fd, list->map, 1000);
	if(i <= 0)
	{
	perror("Error: ");
	exit(0);
	}
	return 1;
}

void line_check(t_list *list)
{
	int temp = 0;
	int i = 0;
	char **map;

	map = ft_split(list->map, '\n');
	while(map[list->line] != NULL)
		list->line++;
	list->line_lenght = ft_strlen(map[0]);
	while(map[temp] != NULL)
	{
		if(map[temp][0] != '1' || map[temp][list->line_lenght - 1] != '1')
		{
			printf("wall error\n");
			exit(0);
		}
		if(ft_strlen(map[temp])!= list->line_lenght)
		{
			printf("line lenght error\n");
			exit(0);
		}
		temp++;
	}
	list->whole_map = map;
	free(map);
}

int map(t_list *list, t_img *img, char **argv)
{
	int i;

	i = 0;
	while(list->map[i])
	{
		if(list->map[i] == '1')
			mlx_put_image_to_window(list->mlx, list->win, img->wall, list->x1, list->y1);
		if(list->map[i] == '2')
			mlx_put_image_to_window(list->mlx, list->win, img->grass, list->x1, list->y1);
		if(list->map[i] == '3')
			mlx_put_image_to_window(list->mlx, list->win, img->player, list->x1, list->y1);
		if(list->map[i] == '4')
			mlx_put_image_to_window(list->mlx, list->win, img->point, list->x1, list->y1);
		list->x1 += 32;
		if(list->map[i] == '\n')
		{
			list->x1 = 0;
			list->y1 += 32;
		}
		i++;
	}
	free(list->map);
	return (0);
}