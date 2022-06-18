/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:43:16 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/02/08 12:20:51 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_et_free(char *buffer, char *buff)
{
	char	*temp;

	temp = ft_strjoin(buffer, buff);
	free(buffer);
	return (temp);
}

char	*ft_lire_fichier(int fd, char *tkt)
{
	char	*buffer;
	int		lire_bytes;

	if (!tkt)
		tkt = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	lire_bytes = 1;
	while (lire_bytes != 0)
	{
		lire_bytes = read(fd, buffer, BUFFER_SIZE);
		if (lire_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[lire_bytes] = 0;
		tkt = ft_join_et_free(tkt, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (tkt);
}

char	*ft_ligne(char *buffer)
{
	char	*ligne;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	ligne = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{	
		ligne[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		ligne[i] = '\n';
	return (ligne);
}

char	*ft_next_ligne(char *buffer)
{
	int		i;
	int		j;
	char	*ligne;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	ligne = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		ligne[j++] = buffer[i++];
	free(buffer);
	return (ligne);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*ligne;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = ft_lire_fichier(fd, buff);
	if (!buff)
		return (NULL);
	ligne = ft_ligne(buff);
	buff = ft_next_ligne(buff);
	return (ligne);
}
