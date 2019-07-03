/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:54 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/03 13:03:29 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

//char ft_join(char s1, char s1)
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
char *ft_join(char *buff, char *here)
{
	static int k;

	k = 0;
	while (buff[k] != '\n' && k < BUFF_SIZE)
	{
		//printf("BUFF %c\n" , buff[k]);
		//here = ft_strjoin(here,buff);
		//printf("Here value %s\n" , temp);
		if (buff[k] == '\n')
			return (NULL);
		//ft_bzero((char*)buff[k] , 1);
		k++;
	}
	here = ft_realloc(here, BUFF_SIZE * 2);
	here = ft_strjoin(here,buff);
	printf("Current value of :%s\n" ,here);
	return (here);
}
int get_next_line(const int fd, char **line)
{
	char *here;
	char *done;
	int k;
	static char *buff;

	k = 0;
	here = ft_strnew(BUFF_SIZE);
	buff = ft_strnew(BUFF_SIZE);
	read (fd, buff, BUFF_SIZE);
	done = ft_strnew(BUFF_SIZE);
	here = ft_strcpy(here, buff);
	//printf("Here value : %s" , here);
	while (ft_next(buff, BUFF_SIZE) != 1)
	{
		read(fd , buff , BUFF_SIZE);
		//line[0] = ft_join(buff, here);
		ft_realloc(done , BUFF_SIZE * 2);
		done  = ft_join(buff, here);
	}
	//line[0] = "nathi";
	//line[1] = "hello";
	printf("Line values: %s" , done);
	//printf("BUFF : %s" , line[1]);
	return (0);
}


// remember while reading your file... do this within a while loop with the condition
// while(ft_strchr(buff, '\n') == NULL)
