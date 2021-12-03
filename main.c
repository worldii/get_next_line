#include "get_next_line.h"
int main(int ac, char **av)
{
 fd1 = open(av[1], O_RDONLY);
 get_next_line(fd1, &line);
 printf("%s", line);
}
