/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:49:45 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/02/25 20:49:21 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
