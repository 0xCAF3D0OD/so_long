/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:52:00 by kdi-noce          #+#    #+#             */
/*   Updated: 2021/11/12 11:40:02 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*val_rt;
	int		i;

	if (!s)
		return (0);
	if (start + len <= ft_strlen(s))
		val_rt = malloc(sizeof (*val_rt) * (len + 1));
	else
		val_rt = malloc(sizeof (*val_rt) * (ft_strlen(s) + 1));
	if (!val_rt)
		return (0);
	i = 0;
	while (s[start] && len-- && start <= ft_strlen(s))
	{
		val_rt[i] = s[start];
		i++;
		start++;
	}
	val_rt[i] = 0;
	return (val_rt);
}
