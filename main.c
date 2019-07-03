/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:30:11 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/02 16:34:06 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int		main(void)
{
	int x;
	char **line2;

	x = open("myfile.txt" , O_RDONLY);
	get_next_line(x, &*line2);
	return (0);
}
