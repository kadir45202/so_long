/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:34:31 by kcetin            #+#    #+#             */
/*   Updated: 2022/06/10 03:58:53 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_up(t_list *list)
{
	if (list->whole_map[list->player_y - 1][list->player_x] != '1'
	&& (list->whole_map[list->player_y - 1][list->player_x] != 'E'
	|| list->coin == 0))
	{
		if (list->whole_map[list->player_y - 1][list->player_x] == 'E')
		{
			exit(0);
		}
		if (list->whole_map[list->player_y - 1][list->player_x] == 'C')
			list->coin_count += 1;
	list->whole_map[list->player_y][list->player_x] = '0';
	list->whole_map[list->player_y - 1][list->player_x] = 'P';
	list->player_y -= 1;
		map(list);
	}
}

void	player_down(t_list *list)
{
	if (list->whole_map[list->player_y + 1][list->player_x] != '1'
	&& (list->whole_map[list->player_y + 1][list->player_x] != 'E'
	|| list->coin == 0))
	{
		if (list->whole_map[list->player_y + 1][list->player_x] == 'E')
			exit(0);
		if (list->whole_map[list->player_y + 1][list->player_x] == 'C')
			list->coin_count += 1;
	list->whole_map[list->player_y][list->player_x] = '0';
	list->whole_map[list->player_y + 1][list->player_x] = 'P';
	list->player_y += 1;
		map(list);
	}
}

void	player_right(t_list *list)
{
	if (list->whole_map[list->player_y][list->player_x + 1] != '1'
	&& (list->whole_map[list->player_y][list->player_x + 1] != 'E'
		|| list->coin == 0))
	{
		if (list->whole_map[list->player_y][list->player_x + 1] == 'E')
		{
			exit(0);
		}
		if (list->whole_map[list->player_y][list->player_x + 1] == 'C')
			list->coin_count += 1;
	list->whole_map[list->player_y][list->player_x] = '0';
	list->whole_map[list->player_y][list->player_x + 1] = 'P';
	list->player_x += 1;
		map(list);
	}
}

void	player_left(t_list *list)
{
	if (list->whole_map[list->player_y][list->player_x - 1] != '1'
	&& (list->whole_map[list->player_y][list->player_x - 1] != 'E'
	|| list->coin == 0))
	{
		if (list->whole_map[list->player_y][list->player_x - 1] == 'E' && list->coin == 0)
		{
			exit(0);
		}
		if (list->whole_map[list->player_y - 1][list->player_x - 1] == 'C')
			list->coin_count += 1;
	list->whole_map[list->player_y][list->player_x] = '0';
	list->whole_map[list->player_y][list->player_x - 1] = 'P';
	list->player_x -= 1;
		map(list);
	}
}

void	more(t_list *l, int i, int j)
{
	while (l->whole_map[i][j] != '\0')
	{
		if (l->whole_map[i][j] == '1')
			mlx_put_image_to_window(l->mlx, l->win, l->wall, l->x1, l->y1);
		if (l->whole_map[i][j] == '0')
			mlx_put_image_to_window(l->mlx, l->win, l->grass, l->x1, l->y1);
		if (l->whole_map[i][j] == 'P')
			mlx_put_image_to_window(l->mlx, l->win,
				l->player, l->x1, l->y1);
		if (l->whole_map[i][j] == 'C')
		{
			mlx_put_image_to_window(l->mlx, l->win,
				l->point, l->x1, l->y1);
				l->coin += 1;
		}
		if (l->whole_map[i][j] == 'E')
			mlx_put_image_to_window(l->mlx, l->win,
				l->enemy, l->x1, l->y1);
		l->x1 += 32;
		j++;
	}
}
