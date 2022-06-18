/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:52:51 by kdi-noce          #+#    #+#             */
/*   Updated: 2021/11/12 11:31:08 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	lendst;

	i = 0;
	j = 0;
	lendst = ft_strlen(dst);
	if (n >= 0)
	{
		while (dst[i])
			i++;
		while (src[j] && i + 1 < n)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		if (j < n)
			dst[i] = '\0';
	}
	if (n < lendst)
		return (ft_strlen(src) + n);
	return (lendst + ft_strlen(src));
}
