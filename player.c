/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by kcetin            #+#    #+#             */
/*   Updated: 2022/06/09 23:48:58 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void player_up(t_list *list)
{
	if(list->whole_map[list->player_y - 1][list->player_x] != '1')
	{
	if(list->whole_map[list->player_y - 1][list->player_x] == 'C')
		list->coin_count += 1;
	list->whole_map[list->player_y][list->player_x] = '0';
	list->whole_map[list->player_y - 1][list->player_x] = 'P';
	list->player_y -= 1;
	map(list);
	}																																																																				
}

void player_down(t_list *list)
{
	if(list->whole_map[list->player_y + 1][list->player_x] != '1')
	{
	if(list->whole_map[list->player_y + 1][list->player_x] == 'C')
		list->coin_count += 1;
	list->whole_map[list->player_y][list->player_x] = '0';
	list->whole_map[list->player_y + 1][list->player_x] = 'P';
	list->player_y += 1;
	map(list);
	}																																																																				
}

void player_right(t_list *list)
{
	if(list->whole_map[list->player_y][list->player_x + 1] != '1')
	{
	if(list->whole_map[list->player_y][list->player_x + 1] == 'C')
		list->coin_count += 1;	
	list->whole_map[list->player_y][list->player_x] = '0';
	list->whole_map[list->player_y][list->player_x + 1] = 'P';
	list->player_x += 1;
	map(list);
	}																																																																				
}

void player_left(t_list *list)
{
	if(list->whole_map[list->player_y][list->player_x - 1] != '1' || list->whole_map[list->player_y][list->player_x - 1] != 'E')
	{
	if(list->whole_map[list->player_y - 1][list->player_x - 1] == 'C')
		list->coin_count += 1;
	
	list->whole_map[list->player_y][list->player_x] = '0';
	list->whole_map[list->player_y][list->player_x - 1] = 'P';
	list->player_x -= 1;
	map(list);
	}																																																																				
}