/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:54 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/08 16:53:17 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
//char ft_join(char s1, char s1)
int ft_next(char *s1, int k)
{
	int b;

	b = 0;
	while (b < k)
	{
		if (s1[b] == '\n')
			return (1);
		if (s1[b] == '\0')
			return (-1);
		b++;
	}
	return (0);	
}
char* ft_first( char *buff, size_t x,char *here)
{
	int j;
	j = 0;
	while (buff[j] != '\n')
	{
		here[x] = buff[j];
		x++;
		j++;
	}
	return (here);
}
char *ft_second(char *second , char *buff)
{
	int j;
	int x;
	j = 0;
	//printf("%s" , buff);
	//x = 0;
	while (buff[j] != '\n')
		j++;
	j++;
	//x = BUFF_SIZE - j;
	while (j < BUFF_SIZE)
		{
			second[j] = buff[j];
			j++;
		}
	printf("%s" , second);
	return (second);
}
char *ft_join( int fd, char *here, char *buff)
{
	int x;
	static int m;
	char temp[BUFF_SIZE+ 1];
	char second[BUFF_SIZE +1];	
	
	x = 0;
	if (m == 1)
		printf("%s" , here);
	x = ft_next(buff , BUFF_SIZE); 
	while ( x < 1)
	{ 
		//x = ft_next(buff , BUFF_SIZE); 
		here = ft_strjoin(here, buff);
		read(fd , buff , BUFF_SIZE);
		//printf("%s" , here);
		x = ft_next(buff , BUFF_SIZE); 
	}
//	printf("%s" , here);	
	if ( x  ==  1)
	{
		//printf("im here!!!");
		//printf("%s" , buff);
		//while (here[m] != '\0')
		//	m++;	
		here = ft_first(buff, ft_strlen(here),here);
		//printf("%s" , here);
		//here =  ft_strcpy(buff , ft_second(second , buff));
		//ft_second(second,buff);
		//prinft("Part2 ,");
	
	}
	printf(" [%d] %s\n" ,m, here);
	//printf("%lu" , ft_strlen(here));
	//printf("\nExtra :%s" , buff);
	//here = ft_strjoin(here , buff);	
	m = m + 1;
	return (here);
}
int get_next_line(const int fd, char **line)
{
	static char buff[BUFF_SIZE + 1];
	static char here[BUFF_SIZE + 1];
	line = (char**)malloc(sizeof(char*));
	*line =  ft_memalloc(BUFF_SIZE);
	//buff = ft_strnew(BUFF_SIZE);
	read(fd, buff, BUFF_SIZE);
	if (fd != 0)
	{
		ft_join(fd ,here, buff);
		//read(fd , buff , BUFF_SIZE);
		if (ft_next(buff , BUFF_SIZE) < 1)
		return (0);
	}
	//printf("%s" , here);
	return (0);
}
/*free ft_strsplit.c

remember while reading your file... do this within a while loop with the condition
while(ft_strchr(buff, '\n') == NULL)*/
