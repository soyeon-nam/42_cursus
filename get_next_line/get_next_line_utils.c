/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:32:47 by snam              #+#    #+#             */
/*   Updated: 2021/05/10 15:32:48 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dst_len;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (src_len + size);
		i = 0;
	while ((i < size - dst_len - 1) && src[i])
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	size_src;
	unsigned int	i;

	if (!dst || !src)
		return (0);
	size_src = ft_strlen(src);
	i = 0;
	while ((i + 1 < dstsize) && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize != 0) 
		dst[i] = 0;
	return (size_src);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if(!ret)
		return (0);
	ft_strlcpy(ret, s1, ft_strlen(s1) + 1);
	ft_strlcat(ret, s2, ft_strlen(s1) + 1);
	return(ret);
}
