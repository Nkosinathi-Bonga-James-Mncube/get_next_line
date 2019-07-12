/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:54 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/11 16:56:29 by nmncube          ###   ########.fr       */
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
		if (s1[b] == '\0')
			return (-1);
		b++;
	}
	return (0);	
}

int ft_count(char *here )
{
	int h;
	h = 0;
	while (here[h] != '\n')
		h++;
	return (h);
}

char *ft_join( int fd, char *temp,char *here, char *buff)
{
	static int m;
	int x;
	static int p;
	char *out;
	//k = 0;
	p = 0;
	m = 0;
	//printf("-->%s" , temp);
	//printf("%s" , buff);
	here = temp;
	out = ft_memalloc(BUFF_SIZE);
	read(fd , buff , BUFF_SIZE);
	//printf("-->%s" , buff);
	x = ft_next(buff, BUFF_SIZE);	
	
	//if (ft_next(her,BUFF_SIZE)== -1)
	//	return(here);//<-solution	
	if (ft_next(here , BUFF_SIZE) == 1) //<-using
	{
		//printf("%s" , here);
		//printf("%s" , buff);
		p = ft_count(here);
		out =ft_strncpy(out , here , p);
		printf("%s\n" , out);// < - here
		p = p + 1;
		///ft_strclr(temp);//think i need this
		//temp = ft_strjoin((char*)&here[p], buff);
		here = ft_strcpy(temp, (char*)&here[p]);
		here=ft_strjoin(temp , buff);
		here = ft_strcpy(temp , here);
		//printf("%s" , out);
		//printf("-->%s" , here);
		m = m+1;
		//printf("-->%s" , buff);
		return (here);
	}
	if (ft_next(buff ,BUFF_SIZE) == -1)
	{
		printf("%s" ,temp);
		return (temp);
	}
	while ( x != 1 && m == 0)
	{ 
		//printf("here+");
		//printf("-->%s" ,buff);
		here = ft_strjoin(here, buff);
		//printf("%s\n" , here);
		read(fd , buff , BUFF_SIZE);
		x = ft_next(buff, BUFF_SIZE);
		m = 0;
	}
	
	while((x == 1) && ft_next(here, BUFF_SIZE) != 1)
	{
		//printf("here2-");
		//printf("-->%s" , buff);
		//printf("%s" , here);	
		//printf("im here");
		p = ft_count(buff);
		//printf("[%d]" , p);
		//printf("%s" , buff);
		out = ft_strncpy(out ,buff,p);
		//printf("-->%s\n" , out);
		here = ft_strjoin(here, out);
		free(out);
		printf("%s\n" , here); //<- here
		p = p + 1;
		ft_strclr(temp);
		here = ft_strcpy(temp , (char*)&buff[p]);
		//printf("-->%s" , temp);
		m = m + 1;     
	   	x = ft_next(here , BUFF_SIZE);
   		//return (here);//<-additional	   
	}
	return (here);
}
int get_next_line(const int fd, char **line)
{
	int k;
	int x;
	k = 0;
	x = BUFF_SIZE;
	static char temp[BUFF_SIZE + 1];
	static char here[BUFF_SIZE + 1]; 
	char buff[x + 1];

	while (x >= k)
	{
		buff[k] = '\0';
		here[k] = '\0';
		k++;
	}
	//printf("%s" , buff);
	//ft_strclr(temp);
	//ft_strclr(here);
	//ft_strclr(buff)
	if (fd != 0)
	{
		ft_join(fd ,temp,here, buff);
	}
	//printf("%s" , buff); 
	return (0);
}
/*free ft_strsplit.c

remember while reading your file... do this within a while loop with the condition
while(ft_strchr(buff, '\n') == NULL)*/
