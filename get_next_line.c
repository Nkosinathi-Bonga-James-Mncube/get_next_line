/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:54 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/06 06:10:16 by nmncube          ###   ########.fr       */
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
		b++;
	}
	return (0);	
}
char *ft_first(char *temp , char *buff)
{
	int k;
	char *s;
	k = 0;
	//printf("%s" , buff);
	while (buff[k] != '\n')
	{
		temp[k] = buff[k];
		k++;
	}
	//s = ft_strtrim(temp);
	//free(temp);
	//printf("%s\n" , temp);
	return (temp);
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
	//printf("%s" , second);
	return (second);
}
char *ft_join( char *here, char *buff)
{
	char temp[BUFF_SIZE+ 1];
	char second[BUFF_SIZE +1];	
	//printf("%s" , here);	
	if (ft_next(buff , BUFF_SIZE) < 1)
	{
		here = ft_strcpy(buff, buff);
		//here = ft_strjoin(here, buff);
		//printf("%s" , here);
	}
	else
	{
		//printf("im here!!!");
		//printf("%s" , buff);
		here = ft_strcpy(buff , ft_first(temp , buff));
		//here = ft_strjoin(here, ft_first(temp, buff));
		//printf("%s" , here);
		//here =  ft_strcpy(buff , ft_second(second , buff));
		//here = ft_strjoin(here, ft_second(second,buff));
		//prinft("Part2 ,");
	}
	printf("%s" , here);
	//here = ft_strjoin(here , buff);	
	return (here);
}
int get_next_line(const int fd, char **line)
{
	static char buff[BUFF_SIZE];
	static char here[BUFF_SIZE];
	int k = 0;
	static int j = 0;
	line = (char**)malloc(sizeof(char*));
	*line =  ft_memalloc(BUFF_SIZE);
	//buff = ft_strnew(BUFF_SIZE);
	read(fd, buff, BUFF_SIZE);
	while (fd != 0)
	{
		ft_join(here, buff);
		//read(fd , buff , BUFF_SIZE);
		if (ft_next(buff , BUFF_SIZE) < 1)
			break ;
		read(fd , buff, BUFF_SIZE);
		//read(fd , buff , BUFF_SIZE);
		//k++;
	}
	j++;
	//printf("%s" , here);
	return (0);
}
/*free ft_strsplit.c

remember while reading your file... do this within a while loop with the condition
while(ft_strchr(buff, '\n') == NULL)*/
