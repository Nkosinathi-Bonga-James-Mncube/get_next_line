/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:54 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/02 16:34:28 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
/*int ft_r_len(int fd)
{
	int k;
	char *buff2;
	buff2 = ft_strnew(1);
	k = 0;
	while (read(fd, buff2,1) > 0)
	{
		if (ft_next(buff2,1) == 0)
			k++;
		else
		break ;
	}
	return (k);
}*/
int ft_next(char *s1, int k)
{
	int b;
	b = 0;
	//if (s1[0] == '\0')
	//	return (1);
	while (b < k)
	{
		if (s1[b] == '\n')
			return (1);
		b++;
	}
	return (0);	
}
/*char *ft_str_k(char *here , char *buff)
{
	int b;
	size_t k;

	k = 0;
	while (buff[k] != '\n')
		k++;
	k++;
	here=ft_strncpy(here,buff, k);
	while (*buff != '\n')
		buff++;
	//printf("\nNumber of char : %d\n" , k);
	return (here);
}*/

int ft_hold (char *s)
{
	int k;
	k = 0;
	k = ft_strlen(s);
	return (k);
}
void ft_r_len( char *here, int fd)
{
	int k;
	char *buff2;
	buff2 = ft_strnew(1);
	k = 0;
	while (buff2[k] != '\n')
	{
		read(fd, buff2 , 1);
		if (ft_next(buff2,1) == 0)
		{
			here = ft_strjoin(here,(char*)buff2);
			k++;
		}
		else
		break ;
	}
	//here = ft_strjoin( (char*)buff2,here);
	ft_hold(here);
	return (here);
	//printf("%s" , here);
}

int get_next_line(const int fd, char **line)
{
	char *buff;
	char *buff3;
	char *here;
	int x;
	int p;
	int b;
	char *f;
	int j;	
	x = 1;
	b = 0;
	j = BUFF_SIZE;
	buff3 = ft_strnew(1);
	ft_r_len(buff3,fd);
	//read(fd,buff,1);
	if (j > ft_hold)
		j = f;
	printf("Value of hold : %d\n" , j);
	//buff = ft_strnew(j);
	//here = ft_strnew(j);
	//free(buff);
	//p = read(fd, buff, BUFF_SIZE);
	//printf("\nsize of %ld" , ft_strlen(buff));
	/*if (j < f)
	here = ft_strcpy(here, buff);
	else
		here = ft_u*/
	/*while(x != 2)
	{
		p = read(fd, buff, BUFF_SIZE);
		//printf("BUFF : %s\n" , here);
		//if (ft_next(buff, BUFF_SIZE))
		//{
			
		//x++;
		//}
		//else
		here = ft_strjoin(here, buff);
		if (ft_next(buff,BUFF_SIZE))
		{
			//printf(" \nBUFF :%s" , buff);
			here = ft_str_k(buff , here);
			//free(buff);
			//printf("\nsize of %ld" , sizeof(buff));
			//printf("\n");
			x++;
		}
		//free(buff);
	}
	/*while (b < 32)
	{
		printf("BUFF :%c , %d\n" ,buff[b], buff[b]);
		b++;
	}*/
	//printf("%s" , here);
	//printf("\nSize of sentence : %d\n" , f);
	return (0);
}


// remember while reading your file... do this within a while loop with the condition
// while(ft_strchr(buff, '\n') == NULL)
