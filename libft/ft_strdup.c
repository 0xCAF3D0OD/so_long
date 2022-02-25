/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:40:45 by kdi-noce          #+#    #+#             */
/*   Updated: 2021/11/12 11:25:29 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*val_dup;
	int		i;

	i = 0;
	val_dup = malloc(sizeof(*val_dup) * (ft_strlen (s)) + 1);
	if (!val_dup)
		return (0);
	while (s[i] != 0)
	{
		val_dup[i] = s[i];
		i++;
	}
	val_dup[i] = 0;
	return (val_dup);
}
