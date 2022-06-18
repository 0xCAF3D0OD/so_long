/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:17:33 by kdi-noce          #+#    #+#             */
/*   Updated: 2021/11/12 11:08:29 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		idx;

	if (dest == src || !n)
		return (dest);
	idx = 0;
	if (dest < src)
	{
		while (idx < n)
		{
			*((char *) dest + idx) = *((char *) src + idx);
			idx++;
		}
	}
	else
	{
		while (n > 0)
		{
			*((char *) dest + n - 1) = *((char *) src + n - 1);
			n--;
		}
	}
	return (dest);
}
