/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:34:31 by kcetin            #+#    #+#             */
/*   Updated: 2022/06/09 23:44:46 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void xpm_to_image(t_list *list, char **argv)
{
	list->wall_path = "./img/wall.xpm";
	list->grass_path = "./img/grass.xpm";
	list->player_path = "./img/player.xpm";
	list->point_path = "./img/point.xpm";
	list->enemy_path = "./img/enemy.xpm";
	list->wall = mlx_xpm_file_to_image(list->mlx, list->wall_path, &list->x, &list->y);
	list->enemy = mlx_xpm_file_to_image(list->mlx, list->enemy_path, &list->x, &list->y);
	list->grass = mlx_xpm_file_to_image(list->mlx, list->grass_path, &list->x, &list->y);
	list->player = mlx_xpm_file_to_image(list->mlx, list->player_path, &list->x, &list->y);
	list->point = mlx_xpm_file_to_image(list->mlx, list->point_path, &list->x, &list->y);
	if(!list->wall || !list->grass || !list->player || !list->point || !list->enemy)
	{
		printf("file not found");
		exit(0);
	}
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
		player_up(list);
	if(key == 0)
		player_left(list);
	if(key == 1)
		player_down(list);
	if(key == 2)
		player_right(list);
	printf("%d %d %d\n", list->step, list->coin_count, list->coin);
	list->step++;
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
			if(list->whole_map[i][line] == '1' || list->whole_map[i][line] == '0'
			|| list->whole_map[i][line] == 'P' || list->whole_map[i][line] == 'C'
			|| list->whole_map[i][line] == 'E')
			{
				line++;
			}
			else
			{
				printf("character error\n");
				exit(0);
			}
		}
		line = 0;
		i++;
	}
}

void find_character(t_list *list)
{
	int i;
	int j;
	j = 0;
	i = 0;

	while(list->whole_map[j] != NULL)
	{
		while(list->whole_map[j][i] != '\0')
		{
			if (list->whole_map[j][i] == 'P')
			{
				list->player_x = i;
				list->player_y = j;
				break;
			}
			i++;
		}
		i = 0;
		j++;
	}
	if(list->player_x == 0)
	{
	printf("there is no player");
	exit(0);
	}
}

int main(int argc, char **argv)
{
	t_list *list = malloc(sizeof(t_list) * 10);
    list->x1 = 0;
    list->y1 = 0;
	
    list->mlx = mlx_init();
	map_to_str(list, argv);
	line_check(list);
    list->win = mlx_new_window(list->mlx, list->line_lenght * 32, list->line * 32, "./so_long");
	find_character(list);
	map_control(list);
    xpm_to_image(list, argv);
	map(list);
	mlx_hook(list->win, 17, 0, ft_exit, 0);
	mlx_hook(list->win, 2, 0, keys, list);
    mlx_loop(list->mlx);
	free(list->whole_map);
	free(list->map);
	free(list);
	return 0;
}