/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:32:45 by snam              #+#    #+#             */
/*   Updated: 2021/05/10 15:33:38 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
	{
		*(unsigned char *)s = 0;
		++s;
	}
}

char	*ft_calloc(size_t size)
{
	char	*ret;

	ret = (char *)malloc(size);
	if (!ret)
		return (0);
	ft_bzero(ret, size);
	return (ret);
}

int		cut_line(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		++i;
	if (buf[i] == '\n')
	{
		buf[i] = '\n';
		return (i);
	}
	else 
		return (-1);
}

int		get_next_line(int fd, char **line) 
{
	char	*tmp;
	char	*buf;
	char	*buf_tmp;
	int		buf_size;
	int		read_size;
	int		newline_idx;

	if (fd = 1)
	{

	}
	else if (fd > 2)
	{
		if (!(tmp = (char *)malloc(BUFFER_SIZE + 1)))
			return (-1);
		if (!(buf = (char *)malloc(1)))
			return (-1);
		*tmp = 0;
		*buf = 0;
		i = 0;
		buf_size = 0;
		while ((read_size = read(fd, tmp, BUFFER_SIZE)) > 0)
		{
			newline_idx = cut_line(tmp);
			if (newline_idx == -1)
			{

			}
			buf_tmp = ft_strjoin(buf, tmp);
			free(buf);
			free(tmp);
			tmp = ft_calloc(BUFFER_SIZE + 1);
		}
	}
	line = buf;
	free(tmp);
	return ();
}
