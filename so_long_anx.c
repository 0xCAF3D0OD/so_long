/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_anx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:49 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/02/25 20:48:37 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

// fonction de merde est reliée a la fonction keyhook;
void	fonction_de_merde(int keycode, t_data *gnl, int mouv)
{
	printf("mouv: %d\n", mouv++);
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

int	keyhook(int keycode, t_data	*gnl)
{
	int			recept;
	static int	mouv;

	mouv++;
	recept = what_is_in_the_map(&*gnl);
	fonction_de_merde(keycode, gnl, mouv);
	return (0);
}
