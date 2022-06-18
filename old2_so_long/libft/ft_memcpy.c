/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:21:33 by kdi-noce          #+#    #+#             */
/*   Updated: 2021/11/12 11:05:32 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*temp;
	char	*tmp;
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	temp = (char *) dest;
	tmp = (char *) src;
	if (i > n)
		return (0);
	while (n > i)
	{
		temp[i] = tmp[i];
		i++;
	}
	return (temp);
}
