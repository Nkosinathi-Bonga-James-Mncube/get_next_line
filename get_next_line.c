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

/*static int ft_next(char *s1, int k)
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
}*/
int get_next_line(const int fd, char **line)
{
	char *buff;
	int total;
	char *here;
	int j;
	ssize_t x;
	int p;
	
	j = 0;
	p = 1;
	total = 0;
	x = BUFF_SIZE;
	here = "test1";
	line = &here;
	buff = ft_memalloc(x);
	p = read(fd, buff, x);
	//printf("%s" , buff);
	while (p > 0)
	{
		//printf("%s" , buff);
		//total = total + ft_next(buff ,x);
		p = read(fd, buff,x);
		if (p != 0 && buff[x - 1] != '\0')
			printf(" BUFF :%s\n" , buff);
		else
			break ;
		//printf("%s" , buff);
	}
//	printf("\nSize of buff : %zu\n" , ft_strlen(buff));
//	printf("Number of n : %d\n" , total);	
	//close(fd);
	free(buff);
	return (0);
}
