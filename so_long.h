/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:03:38 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/02/25 20:46:56 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 800
# define IMG_SIZE 100

# define RED_PIXEL 0xFF000

typedef struct S_perso
{
	int		xperso;
	int		yperso;
	char	*img;
	char	*img_grass;
}			t_perso;

typedef struct S_minlbx
{
	void	*mlx;
	void	*mlx_win;		
}			t_minlbx;

typedef struct S_items
{
	int		c;
	int		e;
	int		p;
	int		x;
	int		y;
	int		stock;
}			t_items;

typedef struct S_map
{
	int		y;
	int		x;
	int		c;
	char	**surf;
	void	*img;
	char	*img2;
}			t_map;

typedef struct S_data
{
	int			fd;
	t_minlbx	*minibx;
	t_map		map;
	t_perso		perso;
	t_items		verify;
}			t_data;

void	init_wind(char **argv1, t_map *map, t_data *gnl, t_minlbx *mlx);
void	init_new_map(char *argv2, t_map *map, t_data *gnl, int line);
int		manage_height(char *_ber);
void	manage_map_in_wind(t_data *gnl, t_minlbx *mlx, int y);
void	manage_bord(t_map *map, t_data *gnl, int h, int line);
int		manage_condition_bord(t_map *map, t_data *gnl, int h, int l);
void	manage_condition(t_data *gnl, char *c, int y);
void	cep_to_zero(t_data *gnl);
void	manage_items_door_player(t_map *map, t_data *gnl, int h, int l);
int		keyhook(int keycode, t_data *gnl);
void	fonction_de_merde(int keycode, t_data *gnl, int mouv);
int		condition(int keycode, t_data *gnl);
void	manage_keyhook(t_data *gnl, int x, int y);
int		what_is_in_the_map(t_data *gnl);
void	manage_door_open(t_data *gnl, int x, int y);
void	manage_exit(t_data *gnl, int recept);
void	ft_close(t_data *gnl, int x, int y);
int		ft_exit(t_minlbx *mlx);
int		check_ber(char *argv);

#endif