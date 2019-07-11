/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:54 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/11 14:57:36 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

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
char* ft_first( char *buff, size_t x,char *here)
{
	int j;
	j = 0;
	int y;
	y = 0;
	char *temp2;

	//printf("%s\n" , here);
	//if ()
	//printf("%s %d\n" , here, ft_next(here , BUFF_SIZE));
	while (buff[y] != '\n')
		y++;
	temp2 = ft_memalloc(ft_strlen(here) + y);
	//printf("%s" ,buff);
	if (ft_next(here ,BUFF_SIZE ) != 1)
		ft_strcpy(temp2, here); //<- COMMENT BACK IF ISSUES OCCUR !!!!/Orginal working before 100
	while (buff[j] != '\n')
	{
		temp2[x] = buff[j];
		x++;
		j++;
	}
	//printf("%s\n" ,temp2);
	return (temp2);
}
char *ft_second(char *here , char *buff)
{
	int j;
	int x;
	j = 0;
	x = 0;
	ft_strclr(here);
	while (buff[j] != '\n')
		j++;
	j++;
	while (buff[j] !='\0')//ft_strcpy
	{
		here[x] = buff[j];
		j++;
		x++;
	}
	//printf("%s" , here);
	return (here);
}
char *ft_join( int fd, char *here, char *buff)
{
	int x;
	static int m;//<- dont need this .Testing only
	static char temp[BUFF_SIZE+ 1];	
	char *tt;
	x = 0;
	//ft_strcpy(here , temp);i< - beter
	here = temp;	
	x = ft_next(buff , BUFF_SIZE); 
	//printf("-->%s" , buff);
	//printf("->%s" , here);
	if( ft_next(here , BUFF_SIZE) == 1)
	{
		//printf("%s" , here);
		//printf("im here");
		m = m + 1;//<- dont need this .Testing only 
		tt = ft_memalloc(BUFF_SIZE);
		tt = ft_second(tt, here);//<- issue with storing in buff
		//printf("%s" ,tt);
		here=ft_first(here,0,tt);
		//printf("%s" , here);
		//printf("[%d]%s\n" ,m, here);
		ft_strclr(temp);
		here = ft_strcpy(temp , tt);
		here = temp;
		here = ft_strjoin(here,buff);
		here = ft_strcpy(temp, here);
		return (0);
	}
	while ( x < 1)
	{ 
		here = ft_strjoin(here, buff);
		read(fd , buff , BUFF_SIZE);
		x = ft_next(buff , BUFF_SIZE);
	}
	if ( x  ==  1)
		here = ft_first(buff, ft_strlen(here),here);
	printf("[%d]%s\n" ,m, here);//<- dont need this .Testing only
	here = ft_second(here, buff);
	here = ft_strcpy(temp, here);
	m = m + 1;//<- dont need this .Testing only
	return (here);
}
int get_next_line(const int fd, char **line)
{
	static char buff[BUFF_SIZE + 1];//remove static?
	static char here[BUFF_SIZE + 1];
	//ft_strclr(here);
	int q;
	q = 0;
	line = (char**)malloc(sizeof(char*));
	*line =  ft_memalloc(BUFF_SIZE);
	read(fd, buff, BUFF_SIZE);
	//printf("%s" ,  buff);
	//if (BUFF_SIZE == 0)
	//	return (here) // < - need help here
	if (fd != 0)
	{
		//if (ft_next(buff , BUFF_SIZE) == 1)
		//	return (0);
		ft_join(fd ,here, buff);
	}
	//printf("%s" , here);
	return (0);
}
/*free ft_strsplit.c

remember while reading your file... do this within a while loop with the condition
while(ft_strchr(buff, '\n') == NULL)*/
