/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:05:03 by kcetin            #+#    #+#             */
/*   Updated: 2022/06/16 15:02:14 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_to_str(t_list *list, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	list->fd = open(argv[1], O_RDONLY);
	list->map = malloc(sizeof(list->map) * 1000);
	i = read(list->fd, list->map, 1000);
	while (list->map[j] != '\0')
	{
		if (list->map[j] == 'C')
		{
			list->coin += 1;
		}
		j++;
	}
	if (i <= 0)
	{
		perror("Error: ");
		exit(0);
	}
	return (1);
}

void	line_check(t_list *list)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	list->whole_map = ft_split(list->map, '\n');
	while (list->whole_map[++list->line] != NULL)
	list->line_lenght = ft_strlen(list->whole_map[0]);
	while (list->whole_map[temp] != NULL)
	{
		if (list->whole_map[temp][0] != '1'
		|| list->whole_map[temp][list->line_lenght - 1] != '1')
			ft_error("wall error");
		if (ft_strlen(list->whole_map[temp]) != list->line_lenght)
			ft_error("line lenght error");
		if (temp == 0 || temp == list->line - 1)
			while (list->whole_map[temp][i])
				if (list->whole_map[temp][i++] != '1')
					exit(0);
		i = 0;
		temp++;
	}
}

void	map(t_list *l)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (l->whole_map[i])
	{
		more(l, i, j);
		l->x1 = 0;
		l->y1 += 32;
		j = 0;
		i++;
	}
}

void	xpm_to_image(t_list *list, char **argv)
{
	list->wall_path = "./img/wall.xpm";
	list->grass_path = "./img/grass.xpm";
	list->player_path = "./img/player.xpm";
	list->point_path = "./img/point.xpm";
	list->enemy_path = "./img/enemy.xpm";
	list->wall = mlx_xpm_file_to_image(list->mlx,
			list->wall_path, &list->x, &list->y);
	list->enemy = mlx_xpm_file_to_image(list->mlx,
			list->enemy_path, &list->x, &list->y);
	list->grass = mlx_xpm_file_to_image(list->mlx,
			list->grass_path, &list->x, &list->y);
	list->player = mlx_xpm_file_to_image(list->mlx,
			list->player_path, &list->x, &list->y);
	list->point = mlx_xpm_file_to_image(list->mlx,
			list->point_path, &list->x, &list->y);
	if (!list->wall || !list->grass || !list->player
		|| !list->point || !list->enemy)
		ft_error("file not found");
}

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit(0);
}
