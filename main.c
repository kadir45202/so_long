/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:34:31 by kcetin            #+#    #+#             */
/*   Updated: 2022/06/10 02:15:42 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(int key)
{
	exit(0);
}

int	keys(int key, t_list *list)
{
	list->x1 = 0;
	list->y1 = 0;
	list->coin = 0;
	if (key == 53 || key == 65307)
	{
		mlx_destroy_window(list->mlx, list->win);
		exit(0);
	}
	if (key == 13 || key == 119)
		player_up(list);
	if (key == 0)
		player_left(list);
	if (key == 1)
		player_down(list);
	if (key == 2)
		player_right(list);
	printf("%d %d %d\n", list->step, list->coin_count, list->coin);
	list->step++;
	return (0);
}

void	map_control(t_list *list)
{
	int		i;
	int		line;
	char	c;

	line = 0;
	i = 0;
	while (list->whole_map[i] != NULL)
	{
		while (list->whole_map[i][line])
		{
			c = list->whole_map[i][line];
			if (c == '1' || c == '0' || c == 'P'
				|| c == 'C' || c == 'E')
				line++;
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

void	find_character(t_list *list)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (list->whole_map[j] != NULL)
	{
		while (list->whole_map[j][i] != '\0')
		{
			if (list->whole_map[j][i] == 'P')
			{
				list->player_x = i;
				list->player_y = j;
				break ;
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (list->player_x == 0)
		ft_error("there is no player");
}

int	main(int argc, char **argv)
{
	t_list	*list;

	list = malloc(sizeof(t_list) * 10);
	list->x1 = 0;
	list->y1 = 0;
	list->mlx = mlx_init();
	map_to_str(list, argv);
	line_check(list);
	list->win = mlx_new_window(list->mlx, list->line_lenght * 32,
			list->line * 32, "./so_long");
	find_character(list);
	map_control(list);
	xpm_to_image(list, argv);
	map(list);
	mlx_hook(list->win, 17, 0, ft_exit, 0);
	mlx_hook(list->win, 2, 0, keys, list);
	mlx_loop(list->mlx);
	return (0);
}
