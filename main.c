/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:18:12 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/24 11:21:33 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
int	main(int argc, char **argv)
{
	char	*line2;
	int		fd;
	int		x;

	fd = open(argv[1], O_RDONLY);
	while ((x = get_next_line(fd, &line2)) > 0)
	{
		ft_putstr(line2);
		ft_putchar('\n');
		free(line2);
	}
	return (0);
}
