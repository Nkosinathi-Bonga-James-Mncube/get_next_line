/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:54 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/16 11:17:58 by nmncube          ###   ########.fr       */
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
int ft_find_n(int p,char *temp,char *buff,char *out, char* here, int m ,char **line)
{
	p = ft_count(buff);
	out = ft_strncpy(out ,buff,p);
	here = ft_strjoin(here, out);
	*line = (char*)malloc(ft_strlen(here) *sizeof(char));
	*line = here;
	p = p + 1;
	ft_strclr(temp);
	here = ft_strcpy(temp , (char*)&buff[p]);
	m = m + 1;
	return (m);
}
int ft_long(int p , char *out,int m, char *here, char *buff,char *temp ,char **line)
{
	char *temp3;

	p = ft_count(here);
	out =ft_strncpy(out , here , p);
	*line = (char*)malloc(ft_strlen(out) *sizeof(char));
	*line = out;
	p = p + 1;
	here = ft_strcpy(temp, (char*)&here[p]);
	here=ft_strjoin(temp , buff);
	temp3 =  here;
	free(here);
	here = ft_strcpy(temp , here);
	m = m + 1;
	free(out);
	return (m);
}

int ft_join( int fd, char *temp,char *here,char *buff, char **line)
{
	static int m;
	static int p;
	char *out;
	char *temp2;
	
	p = 0;
	m = 0;
	here = temp;
	out = ft_memalloc(BUFF_SIZE);
	read(fd , buff, BUFF_SIZE);
	if (ft_strchr(here , '\n') == here)
	{
		m = ft_long(p,out,m,here,buff,temp ,line);
		return (1); //<- leave alone or doesnt work !!
	}
	if (ft_strrchr(buff,'\0') == buff)
	{
		*line = (char*)malloc(ft_strlen(temp) * sizeof(char*));
		*line = temp;
		return (0);
	}
	while (ft_strchr(buff,'\n') == NULL && m == 0)
	{ 
		here = ft_strjoin(here, buff);
		temp2 = here;
		free(here);
		read(fd , buff , BUFF_SIZE);
		m = 0;
	}
	if (ft_strchr(buff,'\n') == buff && ft_strchr(here, '\n') == NULL)
		m = ft_find_n(p,temp,buff, out, here, m ,line);
	free(out);
	//free(temp2);
	return (1);
}
int get_next_line(const int fd, char **line)
{
	int p;
	static char temp[BUFF_SIZE + 1];
	char buff[BUFF_SIZE + 1];
	char *here;
	here = ft_memalloc(BUFF_SIZE + 1);
	ft_bzero(here, BUFF_SIZE +1);
	ft_bzero(buff, BUFF_SIZE + 1);
	p = 0;
	if (BUFF_SIZE <= 0)
		return (-1);//<- is it correct
	p = ft_join(fd ,temp,here,buff,line);
	//free(line);
	return (p);
}
