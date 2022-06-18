/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:49:45 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/03/14 11:42:01 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	manage_other_char(t_map *map, int i[])
{
	int		k;
	char	c;

	k = 0;
	while (k++ < (int)ft_strlen(map->surf[i[2]]) - 1)
	{
		c = map->surf[i[2]][k];
		if (!(c == '1' || c == '0' || c == 'P'
				|| c == 'C' || c == 'E' || c == 'F'))
			return (1);
	}
	if (map->surf[1] && i[0] != (int)ft_strlen(map->surf[i[2] - 1] + 1))
		return (1);
	return (0);
}

int	check_ber(char *argv)
{
	if (!ft_strncmp(argv, "map_1.ber", ft_strlen(argv)))
		return (0);
	else if (!ft_strncmp(argv, "map_2.ber", ft_strlen(argv)))
		return (0);
	else if (!ft_strncmp(argv, "map_3.ber", ft_strlen(argv)))
		return (0);
	else
		return (1);
}
