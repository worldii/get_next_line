/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongha2788 <jongha2788@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:26:30 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/06 17:31:35 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>

int is_newline(char *buf)
{
	int i;
	i = -1;
	while (buf[++i])
	{
		if (buf[i] =='\n')
		return (i);
	}
	return (-1);
}

char * split_line(int oldidx, int nextidx, char * line)
{
	int idx = 0 ;
	line[oldidx + nextidx] = 0;
	return (line+ oldidx + nextidx +1 );
}

char *get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char *backup ;
	char 		*line;
	int			read_size;

	if ( backup == NULL)
		line = ft_strdup ("");
	else
		line = backup;
	if (backup != NULL && is_newline(backup)!= -1)
	{
		backup = split_line (0, is_newline(backup), line);
		return (line);
	}
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = 0;
		int linelen = ft_strlen(line);
		line = ft_strjoin(line, buf);
		int nextidx= is_newline(line); 
		if (nextidx != -1) 
		{
			backup = split_line (linelen, nextidx, line);			
			break;
		}
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	if  (line == NULL || ft_strlen(line) == 0) 
	{
		int nextidx = is_newline(line);
		if (nextidx != -1)
			backup = split_line (0, nextidx, line);
	}
	return (line);
}
