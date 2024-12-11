/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:26:25 by djoung            #+#    #+#             */
/*   Updated: 2024/11/14 00:40:16 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*next_buffer(char **buf, int buf_size)
{
	char	*buf_stack;

	if (!*buf)
		return (NULL);
	if ((*buf)[buf_size] == '\n' || (*buf)[buf_size] != '\0')
	{
		buf_stack = ft_strdup(*buf + buf_size + 1);
		if (!buf_stack)
		{
			free(*buf);
			free(buf_stack);
			return (NULL);
		}
	}
	else
		buf_stack = NULL;
	free(*buf);
	*buf = buf_stack;
	return (*buf);
}

char	*input_line(char **buf, int *buf_size)
{
	char	*line;

	if (!*buf || **buf == '\0')
		return (NULL);
	while ((*buf)[*buf_size] && (*buf)[*buf_size] != '\n')
		(*buf_size)++;
	line = ft_substr(*buf, 0, *buf_size + 1);
	if (!line || !*line)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

int	read_file(int fd, char **buf)
{
	int		read_by;
	char	*new_buf;
	char	*tmp;

	read_by = 1;
	if (!*buf)
		*buf = ft_strdup("");
	new_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_buf)
		return (-1);
	while (read_by && !(ft_strchr(*buf, '\n')))
	{
		read_by = read(fd, new_buf, BUFFER_SIZE);
		if (read_by == -1)
		{
			free(new_buf);
			return (-1);
		}
		new_buf[read_by] = '\0';
		tmp = *buf;
		*buf = ft_strjoin(*buf, new_buf);
		free(tmp);
	}
	free(new_buf);
	return (read_by);
}

char	*free_buf(char **buf, char *line, int read_by)
{
	int	i;

	if (read_by == -1)
	{
		i = 0;
		while (i < 1024)
		{
			if (buf[i] != NULL)
			{
				free(buf[i]);
				buf[i] = NULL;
			}
			i++;
		}
		if (!line)
			free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;
	int			buf_size;
	int			read_by;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_by = read_file(fd, &buf[fd]);
	if (read_by == -1)
	{
		free(buf[fd]);
		buf[fd] = NULL;
		return (NULL);
	}
	buf_size = 0;
	line = input_line(&buf[fd], &buf_size);
	buf[fd] = next_buffer(&buf[fd], buf_size);
	if (!line || !*line)
		return (free_buf(buf, line, read_by));
	return (free_buf(buf, line, read_by));
}
