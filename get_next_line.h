#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H
#define BUFF_SIZE 100

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int get_next_line(const int fd,char **line);

#endif
