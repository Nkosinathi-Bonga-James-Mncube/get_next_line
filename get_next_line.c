#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

static char *ft_leftover(char **line , char *s1)
{
	int		k;
	//int x;
	char *temp2;
	k = 0;
	while (s1[k] != '\0' && s1[k] != '\n')
		k++;
	*line = ft_memalloc(k); 
	ft_strncpy(*line,s1,k);
	if (ft_strcmp(*line , s1) == 0)
		s1 = NULL;
	else
	{	//k++;
		temp2 = s1;
		//s1 = (char*)&temp2[k+1];
		//temp2 =ft_memalloc(ft_strlen(temp2+1+k));
		//s1 = ft_strncpy(temp2,(char*)&s1[k] ,ft_strlen(1 + k);
		//s1 = ft_strncpy(temp2 , k+1,)
		s1= ft_strsub(temp2 , k+1 ,ft_strlen(temp2 +1 + k));
	free(temp2);}
	return(s1);
	/**line=ft_memalloc(k);
	  ft_strncpy(*line,s1,k);
	//printf("%s<-" , *line);
	k++;
	if (ft_strcmp(*line,s1) != 0)
	{
	s1 = (char*)&s1[k];
	return (s1);
	}
	return (NULL);*/
	}
int get_next_line(const int fd, char **line)
{
	static char *temp[1024];
	char *s1;
	char buff[BUFF_SIZE + 1];
	int x;

	x = 1;
	if (fd < 0 || !line || read(fd,buff,0) < 0 )
		return (-1);
	if (!temp[fd])
		temp[fd] = ft_strnew(BUFF_SIZE);
	while ((x = read(fd, buff, BUFF_SIZE)) >  0)
	{
		buff[x]='\0';
		s1 = ft_strjoin(temp[fd] ,buff);
		free(temp[fd]);
		temp[fd] =s1;
		if (ft_strchr(temp[fd], '\n'))
			break ;
	}
	if (x < BUFF_SIZE && !ft_strlen(temp[fd]))
		return (0);
	temp[fd]= ft_leftover(line, temp[fd]);
	return (1);
}
