/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrivino <ctrivino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:03:10 by ctrivino          #+#    #+#             */
/*   Updated: 2022/12/07 17:39:01 by ctrivino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_index(char *value)
{
	int	st;

	st = 0;
	while (value != NULL && value[st] != '\0')
	{
		if (value[st] == '\n')
			return (st);
		st++;
	}
	return (-1);
}

char	*get_my_line(char **value, int index)
{
	char	*line;
	char	*tmp;

	if (index >= 0)
	{
		line = ft_substr(*value, 0, index + 1);
		tmp = ft_substr(*value, index + 1, ft_strlen(*value));
		free(*value);
		*value = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		line = *value;
		*value = NULL;
	}
	return (line);
}

char	*ft_read(int fd, char *value)
{
	char	readed[BUFFER_SIZE + 1];
	char	*aux;
	ssize_t	nr_bytes;

	nr_bytes = 1;
	while (nr_bytes > 0 && ft_strchr(readed, '\n') == 0)
	{
		nr_bytes = read(fd, readed, BUFFER_SIZE);
		if (nr_bytes < 0)
		{
			free(value);
			return (NULL);
		}
		readed[nr_bytes] = '\0';
		aux = ft_strdup(value);
		free(value);
		value = ft_strjoin(aux, readed);
		free(aux);
	}
	return (value);
}

char	*get_next_line(int fd)
{
	static char	*value[OPEN_MAX];
	int			index;
	char		*my_line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	value[fd] = ft_read(fd, value[fd]);
	if (!value[fd])
		return (NULL);
	index = ft_index(value[fd]);
	my_line = get_my_line(&value[fd], index);
	if (ft_strlen(my_line) == 0)
	{
		free(value[fd]);
		free(my_line);
		return (NULL);
	}
	return (my_line);
}
