/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:36:53 by kcetin            #+#    #+#             */
/*   Updated: 2022/06/09 21:33:26 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void player_up(t_list *list)
{
	if(list->whole_map[list->player_y - 1][list->player_x] != '1')
	{
	list->whole_map[list->player_y][list->player_x] = '2';
	list->whole_map[list->player_y - 1][list->player_x] = '3';
	list->player_y -= 1;
	map(list);
	}																																																																				
}

void player_down(t_list *list)
{
	if(list->whole_map[list->player_y + 1][list->player_x] != '1')
	{
	list->whole_map[list->player_y][list->player_x] = '2';
	list->whole_map[list->player_y + 1][list->player_x] = '3';
	list->player_y += 1;
	map(list);
	}																																																																				
}

void player_right(t_list *list)
{
	if(list->whole_map[list->player_y][list->player_x + 1] != '1')
	{
	list->whole_map[list->player_y][list->player_x] = '2';
	list->whole_map[list->player_y][list->player_x + 1] = '3';
	list->player_x += 1;
	map(list);
	}																																																																				
}

void player_left(t_list *list)
{
	if(list->whole_map[list->player_y][list->player_x - 1] != '1')
	{
	list->whole_map[list->player_y][list->player_x] = '2';
	list->whole_map[list->player_y][list->player_x - 1] = '3';
	list->player_x -= 1;
	map(list);
	}																																																																				
}