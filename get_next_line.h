#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#define BUFF_SIZE 4// issue with buff size 11//issue with buff 26//issue with 29//issue with 100
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

int get_next_line(const int fd, char **line);
#endif
