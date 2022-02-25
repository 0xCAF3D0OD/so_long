/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_anx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:49 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/02/24 18:00:03 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	what_is_in_the_map(t_data *gnl)
{
	if (gnl->map.surf[gnl->perso.yperso][gnl->perso.xperso] == 'C' &&
		gnl->map.c > 0)
	{
		gnl->map.c--;
		gnl->map.surf[gnl->perso.yperso][gnl->perso.xperso] = '0';
	}
	if (gnl->map.c == 0)
		return (1);
	else
		return (0);
}

void	manage_keyhook(t_data *gnl, int x, int y)
{
	int	recept;

	mlx_put_image_to_window(gnl->minibx->mlx,
		gnl->minibx->mlx_win,
		gnl->perso.img,
		gnl->perso.xperso * 100,
		gnl->perso.yperso * 100);
	mlx_put_image_to_window(gnl->minibx->mlx,
		gnl->minibx->mlx_win,
		gnl->perso.img_grass,
		gnl->perso.xperso * 100 + x,
		gnl->perso.yperso * 100 + y);
	recept = what_is_in_the_map(&*gnl);
	manage_exit(gnl, recept);
}

int	condition(int keycode, t_data *gnl)
{
	if (keycode == 13
		&& gnl->map.surf[gnl->perso.yperso - 1][gnl->perso.xperso] != '1'
		&& gnl->map.surf[gnl->perso.yperso - 1][gnl->perso.xperso] != 'E')
		return (1);
	if (keycode == 0
		&& gnl->map.surf[gnl->perso.yperso][gnl->perso.xperso - 1] != '1'
		&& gnl->map.surf[gnl->perso.yperso][gnl->perso.xperso - 1] != 'E')
		return (2);
	if (keycode == 1
		&& gnl->map.surf[gnl->perso.yperso + 1][gnl->perso.xperso] != '1'
		&& gnl->map.surf[gnl->perso.yperso + 1][gnl->perso.xperso] != 'E')
		return (3);
	if (keycode == 2
		&& gnl->map.surf[gnl->perso.yperso][gnl->perso.xperso + 1] != '1'
		&& gnl->map.surf[gnl->perso.yperso][gnl->perso.xperso + 1] != 'E')
		return (4);
	if (keycode == 53)
		return (5);
	return (0);
}

int	keyhook(int keycode, t_data	*gnl)
{
	int	recept;

	recept = what_is_in_the_map(&*gnl);
	fonction_de_merde(keycode, gnl);
	return (0);
}
