#include "get_next_line.h"

int	main(int argc, char**argv)
{
	char *line2;
	int fd;

	fd = open (argv[1], O_RDONLY);
	while (get_next_line(fd,&line2) > 0)
	{
		printf("%s\n", line2);
	}
	return (0);
}
