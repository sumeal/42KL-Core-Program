/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:55:02 by abin-moh          #+#    #+#             */
/*   Updated: 2025/02/08 13:55:35 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(int fd, char *line)
{
	char	*buf;
	ssize_t	read_bytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*ft_get_next_line(char *line)
{
	char	*ret;
	int		i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (line [i] && line[i] != '\n')
	{
		ret[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_get_new_line(char *line)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	ret = malloc (sizeof(char) * (ft_strlen(line) - i + 1));
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		ret[j++] = line[i++];
	ret[j] = '\0';
	free(line);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_get_line(fd, line);
	if (!line)
		return (NULL);
	next_line = ft_get_next_line(line);
	line = ft_get_new_line(line);
	return (next_line);
}
