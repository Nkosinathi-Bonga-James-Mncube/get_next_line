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
	//printf("%s" , temp);
	//printf("%s" , buff);
	here = temp;
	out = ft_memalloc(BUFF_SIZE);
	read(fd , buff , BUFF_SIZE);
	//printf("%s" , buff);
	x = ft_next(buff, BUFF_SIZE);	
	while ( x != 1 && m == 0)
	{ 
		//printf("im here");
		here = ft_strjoin(here, buff);
		//printf("%s\n" , here);
		read(fd , buff , BUFF_SIZE);
		x = ft_next(buff, BUFF_SIZE);
		m = 0;
	}
	printf("%s" , here);
	//printf("%s" , buff);
	while(x == 1 && ft_next(here, BUFF_SIZE) != 1)
	{
		//printf("im here");
		p = ft_count(buff);
		//printf("%d" , p);
		//printf("%s" , buff);
		out = ft_strncpy(out ,buff,p);
		//printf("%s" , out);
		here = ft_strjoin(here, out);
		free(out);
		//printf("%s\n" , here);
		p = p + 1;
		ft_strclr(temp);
		here = ft_strcpy(temp , (char*)&buff[p]);
		//printf("%s" , temp);
		m = m + 1;     
	   x = ft_next(here , BUFF_SIZE);	
	}
	//printf("%s" , here);
	return (here);
}
int get_next_line(const int fd, char **line)
{
	static char temp[BUFF_SIZE + 1];
	static char here[BUFF_SIZE + 1]; 
	char buff[BUFF_SIZE + 1];
	ft_strclr(temp);
	ft_strclr(here);
	if (fd != 0)
	{
		ft_join(fd ,temp,here, buff);
	}
	return (0);
}
/*free ft_strsplit.c

remember while reading your file... do this within a while loop with the condition
while(ft_strchr(buff, '\n') == NULL)*/
