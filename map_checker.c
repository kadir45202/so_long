/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:05:03 by kcetin            #+#    #+#             */
/*   Updated: 2022/05/09 20:36:44 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	wall_check(t_list *list)
{
        int i = 0;
        int j = 0;
        char **a;
		a = malloc(1000000);
        a = ft_split(list->map, '\n');
        while(a[i])
                {
                    if(i == 0 || i == 9)
					{
							while(a[i][j++] != '\0' && a[i][j])
							{
								if(a[i][j] != '1')
								{
									return 2;
								}
							}
							j = 0;
					}
					i++;
				}
		return 1;
}

int map_to_str(t_list *list)
{
	int i;
	i = 0;
	list->fd = open("./maps/map.ber", O_RDONLY);
	list->map = malloc(sizeof(list->map) * 1000);
	i = read(list->fd, list->map, 1000);
	if(i <= 0)
		return 0;
	return 1;
}

int map(t_list *list, t_img *img)
{
	int i;
	i = -1;
	map_to_str(list);
	if(wall_check(list) == 2 || map_to_str(list) == 0)
		exit(0);
	while(list->map[i++] != '9')
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
	}
	free(list->map);
	return (0);
}