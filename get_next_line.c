/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongha2788 <jongha2788@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:26:30 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/06 18:08:29 by jonghapa         ###   ########.fr       */
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

char * split_line(char ** buf)
{
	char	*line;
	int newlineidx;
	newlineidx = is_newline(*buf);
	if (newlineidx == -1)
	{
		// 끝이란 이야기임. 
		// buf 의 값 옮겨 담은 다음,  line 의 값에 할당해주고 buf 는 NULL로 초기화
		line = (char *) malloc(sizeof(char) * ft_strlen(*buf) + 1);
		int idx = -1;
		while  (++idx < ft_strlen(*buf))
			line[idx] = (*buf)[idx];
		line[idx] = 0;
	}
	else
	{
		line = (char *) malloc(sizeof(char) * (newlineidx + 1));
		int idx = -1;
		while (++idx < newlineidx)
		{
			line[idx] =(* buf)[idx];
		}
		line[idx] = 0;
		char * temp = (char *) malloc(sizeof(char) * ( ft_strlen(*buf)  - newlineidx + 1));
		idx = -1; 
		while (++idx < ft_strlen(*buf) - newlineidx)
			temp[idx] = (*buf)[newlineidx + idx+ 1] ;
		free(*buf);
		temp[idx] = 0;
		*buf = temp ;
	}
	
	return (line);
}

char *get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char *backup ;
	char 		*line;
	int			read_size;
	
	if ( backup == 0) backup = ft_strdup("");
	if (backup != NULL && is_newline(backup)!= -1)
		return (split_line (&backup));
	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (0);
	while (( read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = 0;
		backup = ft_strjoin(backup, buf);
		int nextidx= is_newline(backup); 
		if (nextidx != -1)
			return (split_line(&backup));
	}
	return (split_line(&backup));
}
