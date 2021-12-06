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
	if (line !=0) printf("printf %s\n", line);
	line = get_next_line ( fd);
	if (line != 0 ) printf("printf %s\n", line);
	line = get_next_line ( fd);
	if (line != 0)printf("printf %s\n", line );
	return (0);
}

