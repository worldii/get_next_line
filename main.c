/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongha2788 <jongha2788@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:41:38 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/09 03:44:40 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "get_next_line.h"
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	fd = open("testfile2", O_RDONLY);
	line = get_next_line(fd);
	while (line!=NULL){
	printf("printf %s", line);

	free(line);
	line = get_next_line (fd);
	}	
	//printf("printf %s", line );
	//free(line);
	return (0);
}*/
