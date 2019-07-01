/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:30:11 by nmncube           #+#    #+#             */
/*   Updated: 2019/06/28 20:51:29 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int		main(void)
{
	int x;
	char *line1;
	char **line2;

	x = open("myfile.txt" , O_RDONLY);
	if (x == -1)
	{
		//ft_putstr("faili\n");
		exit(1);
	}	
	line1= "name";
	line2 = &line1;
	get_next_line(x, line2);
	return (0);
}
