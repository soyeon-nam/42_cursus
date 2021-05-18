/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:59:18 by snam              #+#    #+#             */
/*   Updated: 2021/05/18 19:59:24 by snam             ###   ########.fr       */
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


char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
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
		buf_size = 0;
		while ((read_size = read(fd, tmp, BUFFER_SIZE)) > 0 && ft_strchr(,tmp)/*뉴라인 없음*/)
		{
			
			buf_size += read_size;
			newline_idx = cut_line(tmp);
			buf = ft_calloc(buf_size + 1);

			if (newline_idx == -1)
			{

			}
			buf = ft_strjoin(buf, tmp);
			free(buf);
			free(tmp);
			tmp = ft_calloc(buf_size + 1);
		}
	}
	*line = buf;
	free(tmp);
	return ();
}


int	main()
{
	i = 0;
	while (get_next_line(3, &str))
	{
		printf("%i : %s", str);
		i++;
	}
	
}