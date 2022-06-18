/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:27:18 by kdi-noce          #+#    #+#             */
/*   Updated: 2021/12/10 18:23:52 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	char	*s;

	s = str;
	while (*s != c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return (str);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int		idx;

	if (!str1 && !str2)
		return (0);
	new_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2)) + 1);
	if (!new_str)
		return (0);
	idx = 0;
	while (*str1 != 0 || *str2 != 0)
	{
		if (*str1 == 0)
			new_str[idx++] = *str2++;
		else
			new_str[idx++] = *str1++;
	}
	new_str[idx] = '\0';
	return (new_str);
}

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *)s;
	while (n > 0)
	{
		*temp = 0;
		temp++;
		n--;
	}
	return (*s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*i;

	i = malloc(size * nmemb);
	if (!i)
		return (0);
	ft_bzero (i, nmemb * size);
	return (i);
}
