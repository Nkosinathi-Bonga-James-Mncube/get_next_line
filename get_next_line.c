/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:54 by nmncube           #+#    #+#             */
/*   Updated: 2019/06/29 02:51:04 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
/*static int ft_len_buff(int fd,char *buff, char x)
{
	int k;
	k = 0;
	read(fd, buff, x);
	k = ft_strlen(buff);
	close (fd);
	return (k);
}*/
static int ft_str_buffer(int fd , char *buff , int x)
{
	int k;
	k = 0;

	while (buff[k] != EOF)
	{
		read(fd , buff , x);
		k++;
	}	
	close(fd);
	return (k);
}
int get_next_line(const int fd, char **line)
{
	char *buff;
	int k;
	int j;
	//size_t m;
	int x;
	//int p;
	char *here;
	k = 0;
	j = 0;
	here = "test1";
	line = &here;
	x = BUFF_SIZE;
	buff = ft_memalloc(21);
	//read(fd,buff,BUFF_SIZE);
	/*while (fd != EOF j < ft_str )
	{
	   read(fd, buff,21);
		printf("%s\n" , buff);
		//ft_strclr(buff);
		j++;
	}*/
	//read(fd , buff , BUFF_SIZE);
	k = ft_str_buffer(fd,buff, x);
	printf("Value of k : %d\n" , k);
	//m = ft_len_buff(fd,buff,x);
	//printf("Value of len: %zu\n" , m);
	//p = k / (int)m;
	//printf("Value of p: %d\n" , p);
	//ft_strclr(buff);
	
	while (j <= 9)
	{
		read(fd, buff,10);
		printf("%s\n" , buff);
		j++;
	}
	/*while ( j <= m)
	  {
		  read(fd, buff, k);
		//printf("char : %c\n" , *buff);
		printf("BUFF : %s\n" , buff);
		//printf("Value of j :%d\n" , j);
		//ft_putstr(buff);
		j++;
	}*/
	close(fd);
	return (3);
}
