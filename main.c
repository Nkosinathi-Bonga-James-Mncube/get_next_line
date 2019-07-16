/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:30:11 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/16 11:12:25 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int		main(void)
{
	int x = 0;
	int b;
	b = 1;
	char **line2;
	line2 = (char**)malloc(sizeof(char*));
	x = open("myfile.txt" , O_RDONLY);
	while (b!= 0)
	{
		if (b == 0 || b == -1)
		break ;
		b = get_next_line(x, &*line2);
		printf("%s\n",line2[0]);
	}
	return (0);
}
