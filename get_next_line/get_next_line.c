/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atam <atam@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:00:13 by atam              #+#    #+#             */
/*   Updated: 2024/12/16 13:45:55 by atam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*read_line(int fd, char *buffer, char *line)
{
	int		read_bytes;
	char	*temp_line;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!line)
			line = ft_strdup("");
		temp_line = line;
		line = ft_strjoin(line, buffer);
		free(temp_line);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

static char	*divide_line(char *line, char **line_divided)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	*line_divided = ft_substr(line, 0, i);
	if (!*line_divided)
	{
		free(line);
		return (NULL);
	}
	temp = line;
	line = ft_strdup(line + i);
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*line_divided;
	char		*buffer;
	char		*temp_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	temp_line = read_line(fd, buffer, line);
	free(buffer);
	if (temp_line == NULL || (temp_line[0] == '\0'))
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = divide_line(temp_line, &line_divided);
	return (line_divided);
}
