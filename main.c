#include "get_next_line.h"

int	main(int argc, char**argv)
{
	char *line2;
	int fd;
	int x;

	fd = open (argv[1], O_RDONLY);
	//get_next_line(fd , &line2);
	while (get_next_line(fd,&line2) > 0)
	{
		printf("%s\n", line2);
		//printf("%d\n" ,x);
		free(line2);
	}
	while (1)
	{
	}
	return (0);
}
