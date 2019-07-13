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

int ft_count(char *here )
{
	int h;
	h = 0;
	while (here[h] != '\n')
		h++;
	return (h);
}
//Change ft_Strchr or wont work!!! remove pointer method to array index method!!!
//master version
char *ft_join( int fd, char *temp,char *here, char *buff,char **line)
{
	static int m;
	//int x;
	static int p;
	char *out;

	p = 0;
	m = 0;
	here = temp;
	out = ft_memalloc(BUFF_SIZE);
	read(fd , buff , BUFF_SIZE);
	if (ft_strchr(here , '\n') == here) //<-using
	{
		p = ft_count(here);
		out =ft_strncpy(out , here , p);
		//*line = here;
		//printf("->%s\n",*line);
		printf("%s\n" , out);// < - here
		p = p + 1;
		here = ft_strcpy(temp, (char*)&here[p]);
		here=ft_strjoin(temp , buff);
		here = ft_strcpy(temp , here);
		m = m+1;
		//printf("->%s" , *line);
		return (here);
	}
//	printf("->%s" ,*line);
	if (ft_strrchr(buff ,'\0') == buff)
	{
		printf("%s" ,temp);
		//*line = temp;
		//printf("->%s\n" , *line);
		return (temp);
	}
	while (ft_strchr(buff,'\n') == NULL && m == 0)
	{ 
		here = ft_strjoin(here, buff);
		read(fd , buff , BUFF_SIZE);
		m = 0;
	}
	
	if (ft_strchr(buff,'\n') == buff && ft_strchr(here, '\n') == NULL) //drastic change from while to if//Double check!!!
	{
		p = ft_count(buff);
		out = ft_strncpy(out ,buff,p);
		here = ft_strjoin(here, out);
		//free(out);
		//*line = here;
		printf("%s\n" , here); //<- here
		//printf("->%s\n" , *line);
		p = p + 1;
		ft_strclr(temp);
		here = ft_strcpy(temp , (char*)&buff[p]);
		m = m + 1;     
   		return (here);//<-additional	   
	}
	//printf("->%s\n" ,*line);
	//free(out);
	return (here);
}
int get_next_line(const int fd, char **line)
{
	static int k;
	int p;
	static char temp[BUFF_SIZE + 1];
	char here[BUFF_SIZE + 1]; 
	char buff[BUFF_SIZE + 1];
	ft_bzero(here, BUFF_SIZE +1);
	ft_bzero(buff , BUFF_SIZE + 1);
	p = 0;
	line = (char**)malloc(sizeof(char*));

	if (fd != 0)
	{
		*line = (char*)malloc(sizeof(char));
		ft_join(fd ,temp,here, buff,line);
		//line[k] = *line;
		//k = k + 1;
		//free(*line);
	}
	/*while (line[p] != NULL)
	{
		printf("Store[%d] :%s\n",p , line[p]);
		p++;
	}*/
	//printf("%s" , buff); 
	//free(line);
	return (0);
}
/*free ft_strsplit.c

remember while reading your file... do this within a while loop with the condition
while(ft_strchr(buff, '\n') == NULL)*/
