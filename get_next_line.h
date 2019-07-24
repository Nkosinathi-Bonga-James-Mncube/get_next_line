/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:51:02 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/24 10:55:05 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

int get_next_line(const int fd, char **line);

#endif
