/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:34:31 by kcetin            #+#    #+#             */
/*   Updated: 2022/06/09 21:31:44 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void xpm_to_image(t_list *list, char **argv)
{
	list->wall_path = "./img/wall.xpm";
	list->grass_path = "./img/grass.xpm";
	list->player_path = "./img/player.xpm";
	list->point_path = "./img/point.xpm";
	list->wall = mlx_xpm_file_to_image(list->mlx, list->wall_path, &list->x, &list->y);
	list->grass = mlx_xpm_file_to_image(list->mlx, list->grass_path, &list->x, &list->y);
	list->player = mlx_xpm_file_to_image(list->mlx, list->player_path, &list->x, &list->y);
	list->point = mlx_xpm_file_to_image(list->mlx, list->point_path, &list->x, &list->y);


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
			if (list->whole_map[j][i] == '3')
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
	t_img *img = malloc(sizeof(t_list) * 10);
    list->x1 = 0;
    list->y1 = 0;
	
    list->mlx = mlx_init();
	map_to_str(list, argv);//bir kez kullanılıyor
	//map_control(list);
	line_check(list);
    list->win = mlx_new_window(list->mlx, list->line_lenght * 32, list->line * 32, "./so_long");
	find_character(list);
	//ok
	
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