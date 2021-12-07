/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongha2788 <jongha2788@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:26:30 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/07 14:24:22 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
			return (i);
	}
	return (-1);
}

char	*split_line(char **buf)
{
	char	*line;
	int		idx;
	char	*temp;

	if (*buf[0] == 0)
	{
		free(*buf);
		*buf = NULL;
		return (NULL);
	}
	idx = is_newline(*buf);
	if (idx == -1)
	{
		line = ft_strndup(*buf, 0, ft_strlen(*buf));
		free(*buf);
		*buf = NULL;
	}
	else
	{
		line = ft_strndup(*buf, 0, idx + 1);
		temp = ft_strndup(*buf, idx + 1, ft_strlen(*buf) - idx - 1);
		free(*buf);
		*buf = temp ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup ;
	char		*newbackup;
	int			read_size;
	int			nextidx;

	if (backup != NULL && is_newline(backup) != -1)
		return (split_line (&backup));
	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (0);
	if (backup == 0)
		backup = ft_strndup("", 0, 0);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = 0;
		newbackup = ft_strjoin(backup, buf);
		free(backup);
		backup = newbackup;
		nextidx = is_newline(backup);
		if (nextidx != -1)
			return (split_line(&backup));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (split_line(&backup));
}
