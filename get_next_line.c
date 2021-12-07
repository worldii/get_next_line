/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongha2788 <jongha2788@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:26:30 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/07 13:36:14 by jongha2788       ###   ########.fr       */
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
	int		newlineidx;
	char	*temp;
	
	if (*buf[0] == 0) {
		free(*buf);
		*buf= NULL;
		return (NULL);
	}
	newlineidx = is_newline(*buf);
	if (newlineidx == -1)
	{
		// EOF 라는 뜻임. 
		line = ft_strdup(*buf);
		free(*buf);
		*buf =NULL;
	}
	else
	{
		line = (char *) malloc(newlineidx + 2);
		idx = -1;
		while (++idx <= newlineidx)
			line[idx] = (*buf)[idx];
		line[idx] = 0;
		temp = (char *)malloc(ft_strlen(*buf) - newlineidx );
		idx = -1;
		while (++idx < ft_strlen(*buf) - newlineidx && newlineidx + idx +1 <ft_strlen(*buf))
			temp[idx] = (*buf)[newlineidx + idx + 1];
		temp[idx] = 0;
		free(*buf);
		*buf = temp ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup ;
	char *newbackup;
	int			read_size;
	int			nextidx;

	if (backup != NULL && is_newline(backup) != -1)
		return (split_line (&backup));
	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (0);
	if (backup == 0)
		backup = ft_strdup("");

	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = 0;
		newbackup = ft_strjoin(backup, buf);
		free(backup);
		backup = newbackup;
		if ((nextidx = is_newline(backup)) != -1)
			return (split_line(&backup));
	}
	return (split_line(&backup));
}
