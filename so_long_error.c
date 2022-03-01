/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:20:59 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/03/01 10:10:42 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_minlbx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(1);
}

void	cep_to_zero(t_data *gnl)
{
	gnl->verify.c = 0;
	gnl->verify.e = 0;
	gnl->verify.p = 0;
	gnl->verify.x = 0;
	gnl->verify.y = 0;
	gnl->verify.stock = 0;
}

void	manage_items_door_player(t_map *map, t_data *gnl, int h, int l)
{
	int		x;

	x = map->x;
	while (map->surf[map->y][x - 1] > 0)
	{
		if (map->surf[map->y][x] == 'P')
			gnl->verify.p++;
		if (map->surf[map->y][x] == 'C')
			gnl->verify.c++;
		if (map->surf[map->y][x] == 'E')
			gnl->verify.e++;
		x--;
	}
	if (l == h)
	{
		if (gnl->verify.p == 0 || gnl->verify.p >= 2)
			(write(1, "ERROR\nto much or no perso", 26), exit(1));
		if (gnl->verify.c == 0)
			exit(1);
		if (gnl->verify.e == 0 || gnl->verify.e >= 2)
			(write(1, "ERROR\nto much or no exit", 25), exit(1));
	}
}
