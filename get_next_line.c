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

static int ft_next(char *s1, int k)
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
/*char *ft_str(char *buff,char *here,int x)
{
	int b;
	char temp[x];
	ft_memalloc(temp);
	b = 0;
	while (buff[b] != '\n')
	{
		buff[]	
		b++;
	}
	return ()
	free(temp);
}*/	
int get_next_line(const int fd, char **line)
{
	char *buff;
	char *here;
	int x;
	int p;
	
	x = 1;
	buff = ft_strnew(BUFF_SIZE);
	here = ft_strnew(BUFF_SIZE);
	p = read(fd, buff, BUFF_SIZE);
	here = ft_strcpy(here, buff);
	while(x != 2)
	{
		p = read(fd, buff, BUFF_SIZE);
		//printf("BUFF : %s\n" , here);
		//if (ft_next(buff, BUFF_SIZE))
		//{
			
		//	x++;
		//}else
			here = ft_strjoin(here, buff);
		if (ft_next(buff,BUFF_SIZE))
			x++;
		//free(buff);
	}
	printf("%s" , here);
	return (0);
}


// remember while reading your file... do this within a while loop with the condition
// while(ft_strchr(buff, '\n') == NULL)
