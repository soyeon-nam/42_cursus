/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 06:43:00 by snam              #+#    #+#             */
/*   Updated: 2021/06/01 17:46:38 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	ret;

	ret = 0;
	while (s[ret])
		++ret;
	return (ret);
}

void		ft_strncpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	while ((i + 1 < size) && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	if (size != 0)
		dst[i] = 0;
}

void		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dst_len;

	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return ;
	i = 0;
	while ((i < size - dst_len - 1) && src[i])
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
}

char		*ft_strjoin(char **s1, char **s2)
{
	char	*ret;

	if (!*s1 || !*s2)
		return (0);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(*s2) + 1));
	if (!ret)
		return (0);
	ft_strncpy(ret, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(ret, *s2, ft_strlen(*s1) + ft_strlen(*s2) + 1);
	free(*s1);
	free(*s2);
	*(char **)s2 = 0;
	return (ret);
}

int			split_nl(char **dst, char **src)
{
	unsigned int	size_src;
	unsigned int	size_dst;
	char			*src_ptr;
	
	src_ptr = *src;
	while (*src_ptr && *src_ptr != '\n')
		++src_ptr;
	if (*src_ptr == '\n')
	{
		size_dst = src_ptr - *src;
		size_src = ft_strlen(*src) - size_dst - 1;
		if (!(*dst = (char *)malloc(size_dst + 1)))
			return (-1);
		ft_strncpy(*dst, *src, size_dst + 1);
		src_ptr = *src;
		if (!(*src = (char *)malloc(size_src + 1)))
		{
			free(*dst);
			*dst = 0;
			return (-1);
		}
		ft_strncpy(*src, &src_ptr[size_dst + 1], size_src + 1);
		free(src_ptr);
		return (1);
	}
	*dst = *src;  //*src_ptr == '\0'
	*src = 0;
	return (0);
}
