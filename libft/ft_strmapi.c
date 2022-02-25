/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:53:39 by kdi-noce          #+#    #+#             */
/*   Updated: 2021/11/12 11:34:28 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_ini;
	char	*str;
	int		i;

	str_ini = (char *) s;
	if (!str_ini)
		return (0);
	str = malloc (sizeof(char) * ft_strlen(str_ini) + 1);
	if (!str)
		return (NULL);
	if (!str)
	{
		str[0] = 48;
		return (str);
	}
	i = 0;
	while (str_ini[i] != 0)
	{
		str[i] = (*f)(i, str_ini[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
