/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongha2788 <jongha2788@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:26:30 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/05 17:12:42 by jongha2788       ###   ########.fr       */
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

char * split_line(int nextidx, char *buf)
{

}
char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE];
	static char * temp =ft_strdup("");
	int	read_size;
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0 ) {
		buf[read_size] = 0;
		temp = ft_strjoin (temp, buf);
		int nextidx= is_newline(temp);
		// 동적 할당을 해줌. buf 같은 경우 local variable 이기 때문에 이 함수가 사라지면 잃어버림. 
		if (nextidx != -1) 
		{
			// 바로 이전의 줄과 split 한 것 합친 다음에 리턴
			// 다음에 next 줄을 읽기 위해서는 \n 이후의 글자를 가르키게 해야함.
			
		}
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	
	return (temp);
}
