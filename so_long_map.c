/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:53:05 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/03/01 10:11:25 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	manage_condition(t_data *gnl, char *c, int y)
{
	int	xp;
	int	yp;
	int	x;

	x = gnl->map.x;
	gnl->map.img = mlx_xpm_file_to_image(gnl->minibx->mlx, c, &xp, &yp);
	mlx_put_image_to_window(gnl->minibx->mlx, gnl->minibx->mlx_win,
		gnl->map.img, x * 100, y * 100);
	if (gnl->map.surf[y][gnl->map.x] == '0')
		gnl->perso.img_grass = gnl->map.img;
	if (gnl->map.surf[y][gnl->map.x] == 'C')
	{
		gnl->map.c++;
		gnl->map.c = gnl->map.c;
	}
	if (gnl->map.surf[y][gnl->map.x] == 'P')
	{
		gnl->perso.xperso = gnl->map.x;
		gnl->perso.yperso = y;
		gnl->perso.img = gnl->map.img;
		gnl->map.surf = gnl->map.surf;
	}
}

void	manage_map_in_wind(t_data *gnl, t_minlbx *minibx, int y)
{
	gnl->minibx = minibx;
	gnl->map.c = 0;
	while (gnl->map.surf[y])
	{
		gnl->map.x = 0;
		while (gnl->map.surf[y][gnl->map.x])
		{
			if (gnl->map.surf[y][gnl->map.x] == '1')
				manage_condition(gnl, "./image/briques.xpm", y);
			if (gnl->map.surf[y][gnl->map.x] == '0')
				manage_condition(gnl, "./image/grass.xpm", y);
			if (gnl->map.surf[y][gnl->map.x] == 'C')
				manage_condition(gnl, "./image/item.xpm", y);
			if (gnl->map.surf[y][gnl->map.x] == 'E')
				manage_condition(gnl, "./image/door.xpm", y);
			if (gnl->map.surf[y][gnl->map.x] == 'P')
				manage_condition(gnl, "./image/WAWA.xpm", y);
			gnl->map.x++;
		}
		y++;
	}
}

int	manage_height(char *_ber)
{
	int		fd;
	char	*temp;
	int		h;

	h = 0;
	fd = open(_ber, O_RDONLY);
	if (fd < 0)
		return (0);
	else
	{
		temp = get_next_line(fd);
		while (temp)
		{
			h++;
			free(temp);
			temp = get_next_line(fd);
		}
		close(fd);
	}
	return (h);
}

void	init_new_map(char *argv2, t_map *map, t_data *gnl, int line)
{
	char		*boucle;
	int			h;

	h = manage_height(argv2);
	map->surf = calloc(h + 1, sizeof (char *));
	gnl->fd = open(argv2, O_RDONLY);
	if (gnl->fd == -1 || check_ber(argv2) == 1)
		(write(2, "ERROR argv\n", 12), exit(1));
	boucle = get_next_line(gnl->fd);
	while (boucle)
	{
		map->surf[map->y] = calloc(strlen(boucle), sizeof(char));
		while (boucle[map->x] != '\0' && boucle[map->x] != '\n')
		{
			map->surf[map->y][map->x] = boucle[map->x];
			map->x++;
		}
		line++;
		manage_bord(map, gnl, h, line);
		map->surf[map->y][map->x] = 0;
		map->x = 0;
		free(boucle);
		boucle = get_next_line(gnl->fd);
		map->y++;
	}
}

void	init_wind(char **argv1, t_map *map, t_data *gnl, t_minlbx *minibx)
{
	int			x;
	int			y;
	static int	line;

	x = 0;
	y = 0;
	line = 0;
	init_new_map(argv1[1], map, gnl, line);
	while (map->surf[y])
	{
		while (map->surf[y][x])
			x++;
		y++;
	}
	minibx->mlx_win = mlx_new_window(minibx->mlx, x * 100, y * 100, "mlx_42");
	gnl->map.surf = map->surf;
	y = 0;
	manage_map_in_wind(gnl, minibx, y);
}
