/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:05:03 by kcetin            #+#    #+#             */
/*   Updated: 2022/06/10 00:10:30 by kcetin           ###   ########.fr       */
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
	return (1);
}

void line_check(t_list *list)
{
	int temp = 0;
	int i = 0;
	list->whole_map = malloc(sizeof(char *) * 100);
	list->whole_map = ft_split(list->map, '\n');
	while(list->whole_map[++list->line] != NULL)
	list->line_lenght = ft_strlen(list->whole_map[0]);
	while(list->whole_map[temp] != NULL)
	{
		if(list->whole_map[temp][0] != '1' || list->whole_map[temp][list->line_lenght - 1] != '1')
		{
			printf("wall error\n");
			exit(0);
		}
		if(ft_strlen(list->whole_map[temp])!= list->line_lenght)
		{
			printf("line lenght error\n");
			exit(0);
		}
		if(temp == 0 || temp == list->line - 1)
			while (list->whole_map[temp][i])
				if(list->whole_map[temp][i++] != '1')
					exit(0);
		i = 0;
		temp++;
	}
}

int map(t_list *list)
{
	int i;
	int j;
	j = 0;
	i = 0;
	list->x1 = 0;
	list->y1 = 0;
	list->coin = 0;
	while(list->whole_map[i])
	{
		while(list->whole_map[i][j] != '\0')
		{
		if(list->whole_map[i][j] == '1')
			mlx_put_image_to_window(list->mlx, list->win, list->wall, list->x1, list->y1);
		if(list->whole_map[i][j] == '0')
			mlx_put_image_to_window(list->mlx, list->win, list->grass, list->x1, list->y1);
		if(list->whole_map[i][j] == 'P')
			mlx_put_image_to_window(list->mlx, list->win, list->player, list->x1, list->y1);
		if(list->whole_map[i][j] == 'C')
		{
			mlx_put_image_to_window(list->mlx, list->win, list->point, list->x1, list->y1);
			list->coin += 1;
		}
		if(list->whole_map[i][j] == 'E')
			mlx_put_image_to_window(list->mlx, list->win, list->enemy, list->x1, list->y1);
		list->x1 += 32;
		j++;
		}
		list->x1 = 0;
		list->y1 += 32;
		j = 0;
		i++;
	}
	return (0);
}