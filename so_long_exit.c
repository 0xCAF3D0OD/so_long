/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:09:48 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/02/24 19:09:41 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close(t_data *gnl, int x, int y)
{
	if (gnl->map.surf[y][x] == 'F')
		exit(1);
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
	int	max;
	int	test;
	int	haut;

	max = ft_strlen(map->surf[map->y] + 1);
	test = map->x;
	haut = map->y;
	if (test < max)
		(write(1, "ERROR\n", 7), exit(1));
	while (max-- > 0 && test--)
	{
		if (map->surf[0][test] != '1')
			return (1);
		if (l == h)
		{
			if (map->surf[l - 1][test] != '1')
				return (3);
		}
	}
	manage_items_door_player(map, gnl, h, l);
	max = ft_strlen(map->surf[map->y]);
	if (map->surf[haut][0] != '1' || map->surf[haut][max - 1] != '1')
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

// fonction de merde est reliée a la fonction keyhook;
void	fonction_de_merde(int keycode, t_data *gnl)
{
	if (condition(keycode, gnl) == 1)
	{
		gnl->perso.yperso--;
		manage_keyhook(gnl, 0, 100);
	}
	if (condition(keycode, gnl) == 2)
	{
		gnl->perso.xperso--;
		manage_keyhook(gnl, 100, 0);
	}
	if (condition(keycode, gnl) == 3)
	{
		gnl->perso.yperso++;
		manage_keyhook(gnl, 0, -100);
	}
	if (condition(keycode, gnl) == 4)
	{
		gnl->perso.xperso++;
		manage_keyhook(gnl, -100, 0);
	}
	if (condition(keycode, gnl) == 5)
		exit(1);
}
