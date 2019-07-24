/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:46:49 by nmncube           #+#    #+#             */
/*   Updated: 2019/07/24 12:23:34 by nmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

char		*ft_cpy(char *dst, const char *src, size_t len)
{
	size_t k;

	k = 0;
	while (k < len && src[k] != '\0')
	{
		dst[k] = src[k];
		k++;
	}
	dst[k] = '\0';
	return (dst);
}

static char	*ft_leftover(char **line, char *s1)
{
	int		k;

	k = 0;
	while (s1[k] != '\0' && s1[k] != '\n')
		k++;
	*line = ft_memalloc(k);
	ft_cpy(*line, s1, k);
	if (ft_strcmp(*line, s1) == 0)
		s1 = NULL;
	else
		s1 = ft_cpy(s1, (char*)&s1[k + 1], ft_strlen(s1 + 1 + k));
	return (s1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*temp[1024];
	char		*s1;
	char		buff[BUFF_SIZE + 1];
	int			x;

	x = 1;
	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!temp[fd])
		temp[fd] = ft_strnew(BUFF_SIZE);
	while ((x = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[x] = '\0';
		s1 = ft_strjoin(temp[fd], buff);
		free(temp[fd]);
		temp[fd] = s1;
		if (ft_strchr(temp[fd], '\n'))
			break ;
	}
	if (x < BUFF_SIZE && !ft_strlen(temp[fd]))
		return (0);
	temp[fd] = ft_leftover(line, temp[fd]);
	return (1);
}
