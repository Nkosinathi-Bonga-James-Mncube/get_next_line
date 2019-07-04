/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:26:54 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/04 15:55:57 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
//char ft_join(char s1, char s1)
int ft_next(char *s1, int k)
{
	int b;

	b = 0;
	while (b < k)
	{
		if (s1[b] == '\n')
			return (1);
		b++;
	}
	return (0);	
}
char *ft_word(char *here ,int fd)
{
	int k;
	int j;
	static char *word;
	int bfound;
	char temp[BUFF_SIZE];
	word =  ft_strnew(BUFF_SIZE);
	k = 0;
	j = 0;
	bfound = 0;
	while (word[k] != '\n')
	{
		//if ()
		read (fd, word, BUFF_SIZE);
		if (ft_next(word , BUFF_SIZE) == 0)
		{
			here = ft_strjoin(here , (char*)word);
			k++;
		}
		else
		{
			bfound = 1;
			break ;
		}
	}
	if (bfound == 1)
	{
		while (word[j] != '\n')
		{
			temp[j] = word[j];
			j++;
		}
		here = ft_strjoin(here , temp);
	}
	//ft_bzero(temp, BUFF_SIZE);
	word = ft_strsub(word,j + 1, BUFF_SIZE);
	//here = ft_strjoin(here ,word);
	printf("%s\n" , here);
	printf("%s" , word);
	free(word);
	return (here);
}
int get_next_line(const int fd, char **line)
{
	char *here;
	char *name;
	int k;
	k = 0;
	//line = &name;
	//read(fd, buff)
	here = ft_strnew(BUFF_SIZE);

	if (fd != 0)
	{
		line[k] = *ft_strsplit(ft_word(here ,fd) , '\n');
	}
	//k = 0;
	//printf("Store [%d] : %s" , k,line[k]);
	free(here);
	return (0);
}
//free ft_strsplit.c

// remember while reading your file... do this within a while loop with the condition
// while(ft_strchr(buff, '\n') == NULL)
