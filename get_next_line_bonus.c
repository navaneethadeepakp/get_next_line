/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:32:21 by naperisw          #+#    #+#             */
/*   Updated: 2025/04/15 09:02:07 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_updatebuffer(char *s_buffer)
{
	int		i;
	char	*new_buffer;

	i = 0;
	while (s_buffer[i] && s_buffer[i] != '\n')
		i++;
	if (!s_buffer[i])
	{
		free(s_buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc((ft_strlen(s_buffer) - i) * sizeof(char));
	if (!new_buffer)
	{
		free (s_buffer);
		return (NULL);
	}
	ft_memmove(new_buffer, s_buffer + i + 1,
		ft_strlen(s_buffer) - i - 1);
	new_buffer[ft_strlen(s_buffer) - i - 1] = '\0';
	free(s_buffer);
	return (new_buffer);
}

static char	*ft_get_one_line(char *s_buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!s_buffer || !s_buffer[i])
		return (NULL);
	while (s_buffer[i] && s_buffer[i] != '\n')
		i++;
	if (s_buffer[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_memmove(line, s_buffer, i);
	line[i] = '\0';
	return (line);
}

static char	*ft_read_from_fd(int fd, char *s_buffer)
{
	char	read_buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*new_buffer;

	bytes_read = 1;
	while (!ft_strchr(s_buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (s_buffer);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		new_buffer = ft_strjoin(s_buffer, read_buffer);
		if (!new_buffer)
		{
			free(s_buffer);
			return (NULL);
		}
		s_buffer = new_buffer;
	}
	return (s_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_from_fd(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_one_line(buffer[fd]);
	if (!line)
	{
		free (buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_updatebuffer(buffer[fd]);
	return (line);
}
