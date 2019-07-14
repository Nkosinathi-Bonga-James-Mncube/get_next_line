/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:54 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/14 15:35:21 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int ft_count(char *here)
{
	int h;
	h = 0;
	while (here[h] != '\n')
		h++;
	return (h);
}
//mealloc for line !important
//condition for BUFF_SIZE <= 0
int ft_find_n(int p,char *temp,char *line,char *out, char* here, int m)
{
	p = ft_count(line);
	out = ft_strncpy(out ,line,p);
	here = ft_strjoin(here, out);
	//free(out);
	//printf("->%s\n" , here);
	//line = here;//print here;
	p = p + 1;
	ft_strclr(temp);
	here = ft_strcpy(temp , (char*)&line[p]);
	m = m + 1;
	return (m);
}
int ft_join( int fd, char *temp,char *here,char *line)
{
	static int m;
	static int p;
	char *out;

	p = 0;
	m = 0;
	here = temp;
	out = ft_memalloc(BUFF_SIZE);
	read(fd , line, BUFF_SIZE);
	if (ft_strchr(here , '\n') == here)
	{
		p = ft_count(here);
		out =ft_strncpy(out , here , p);
		//printf("->%s\n" , here);
		//line = out;//print here
		p = p + 1;
		here = ft_strcpy(temp, (char*)&here[p]);
		here=ft_strjoin(temp , line);
		here = ft_strcpy(temp , here);
		m = m + 1;
		free(line);
		return (1); //<- leave alone or doesnt work !!
	}
	if (ft_strrchr(line,'\0') == line)
	{
		//printf("->%s\n" ,temp);
		//line = temp; //print here
		free(line);
		return (0);
	}
	while (ft_strchr(line,'\n') == NULL && m == 0)
	{ 
		here = ft_strjoin(here, line);
		read(fd , line , BUFF_SIZE);
		m = 0;
	}	
	if (ft_strchr(line,'\n') == line && ft_strchr(here, '\n') == NULL) //drastic change from while to if//Double check!!!
	{
		m = ft_find_n(p,temp,line, out, here, m);
	}
	free(out);
	return (1);
}
int get_next_line(const int fd, char **line)
{
	int p;
	static char temp[BUFF_SIZE + 1];
	char here[BUFF_SIZE + 1];

	ft_bzero(here, BUFF_SIZE +1);
	p = 1;
	if (BUFF_SIZE <= 0)
		return (-1);//<- is it correct
	line = (char**)malloc(sizeof(char*));
	while (p)
	{
		*line = (char*)malloc(BUFF_SIZE * sizeof(char));
		p = ft_join(fd ,temp,here,*line);
		//printf("%d\n" , p);
		if (p == 0)
			break ;
	}
	//printf("%d\n" , p);
	free(line);
	return (p);
}
