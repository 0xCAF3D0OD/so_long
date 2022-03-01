/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:09:48 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/03/01 11:04:40 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close(t_data *gnl, int x, int y)
{
	if (gnl->map.surf[y][x] == 'F')
		exit(1);
}

void	manage_door_open(t_data *gnl, int x, int y)
{
	if (gnl->map.surf[y][x + 1] == 'E')
	{
		x++;
		gnl->map.surf[y][x] = 'F';
	}
	if (gnl->map.surf[y][x - 1] == 'E')
	{
		x--;
		gnl->map.surf[y][x] = 'F';
	}
	if (gnl->map.surf[y + 1][x] == 'E')
	{
		y++;
		gnl->map.surf[y][x] = 'F';
	}
	if (gnl->map.surf[y - 1][x] == 'E')
	{
		y--;
		gnl->map.surf[y][x] = 'F';
	}
	ft_close(gnl, x, y);
}

void	manage_exit(t_data *gnl, int recept)
{
	int	x;
	int	y;

	x = gnl->perso.xperso;
	y = gnl->perso.yperso;
	if (recept == 1 && (gnl->map.surf[y][x + 1] == 'E'
		|| gnl->map.surf[y][x - 1] == 'E'
		|| gnl->map.surf[y + 1][x] == 'E'
		|| gnl->map.surf[y - 1][x] == 'E'))
		manage_door_open(gnl, x, y);
}

int	manage_condition_bord(t_map *map, t_data *gnl, int h, int l)
{
	int	arr[3];

	arr[0] = ft_strlen(map->surf[map->y] + 1);
	arr[1] = map->x;
	arr[2] = map->y;
	if (map->surf[1] && arr[0] != (int)ft_strlen(map->surf[map->y - 1] + 1))
		(write(1, "ERROR\n", 7), exit(1));
	while (arr[0]-- > 0 && arr[1]--)
	{
		if (map->surf[0][arr[1]] != '1')
			return (1);
		if (l == h)
		{
			if (map->surf[l - 1][arr[1]] != '1')
				return (3);
		}
	}
	manage_items_door_player(map, gnl, h, l);
	arr[0] = ft_strlen(map->surf[map->y]);
	if (map->surf[arr[2]][0] != '1' || map->surf[arr[2]][arr[0] - 1] != '1')
		return (2);
	else
		return (0);
}

void	manage_bord(t_map *map, t_data *gnl, int h, int line)
{
	int	i;
	int	max;

	i = manage_condition_bord(map, gnl, h, line);
	if (i == 1)
		(write(1, "ERROR\nmiss '1' of the first line", 33), exit(1));
	else if (i == 2)
		(write(1, "ERROR\nmiss '1' at the side line", 32), exit(1));
	else if (i == 3)
		(write(1, "ERROR\nmiss '1' of the last line", 32), exit(1));
	if (line == h)
	{
		max = ft_strlen(map->surf[map->y]);
		if (h == max)
			(write(1, "ERROR\nthe map can't be squarish", 32), exit(1));
	}	
}
