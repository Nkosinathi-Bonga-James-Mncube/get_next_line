/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:30:11 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/15 10:56:34 by nmncube          ###   ########.fr       */
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

	x = open("myfile.txt" , O_RDONLY);
	while (b == 1)
	{
		b = get_next_line(x, &*line2);

		if (b == 0 || b == -1)
		break ;
	}
	return (0);
}
