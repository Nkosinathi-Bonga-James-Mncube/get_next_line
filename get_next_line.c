#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

static char *ft_leftover(char **line , char *s1)
{
	char *s2;
	int k;
	k = 0;

	while (s1[k] != '\0' && s1[k] != '\n')
		k++;
	*line = ft_strncpy(*line,s1,k);
	k++;
       if (!ft_strcmp(*line,s1) == 0)
       {
	s1 = (char*)&s1[k];
	return (s1);	
       }
       else
	       return (NULL);
}
char *ft_j_words(char *temp ,char *buff)
{	char *s1;

	s1 = ft_strjoin(temp, buff);
	free(temp);
	return (s1);
}
int get_next_line(const int fd, char **line)
{
	static char *temp[1024];
	char *s1;
	char buff[BUFF_SIZE + 1];
	int x;

	x =1;
	if (fd < 0 || !line || read(fd,buff,0) < 0 )
		return (-1);
	if (!temp[fd])
		temp[fd] = ft_strnew(BUFF_SIZE);
	while ((x = read(fd, buff, BUFF_SIZE)) >  0)
	{
		buff[x]='\0';
		s1 = ft_j_words(temp[fd] , buff);
		temp[fd] =s1;
		if (ft_strchr(temp[fd], '\n'))
			break ;
	}
	if (x < BUFF_SIZE && !ft_strlen(temp[fd]))
		return (0);	
	temp[fd]= ft_leftover(line, temp[fd]);
	return (1);
}
