/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:21:25 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/03/03 13:58:56 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map		map;
	t_data		gnl;
	t_minlbx	minibx;

	if (argc < 2 || argc > 2)
		return (0);
	cep_to_zero(&gnl);
	minibx.mlx = mlx_init();
	init_wind(&*argv, &map, &gnl, &minibx);
	gnl.minibx = &minibx;
	mlx_key_hook(minibx.mlx_win, keyhook, &gnl);
	mlx_hook(minibx.mlx_win, 17, 1L, ft_exit, &minibx);
	mlx_loop(minibx.mlx);
}

	//_CrtDumpMemoryLeaks();