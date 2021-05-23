/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:01:00 by marvin            #+#    #+#             */
/*   Updated: 2021/05/23 01:01:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	size_src;
	unsigned int	i;

	size_src = ft_strlen(src);
	i = 0;
	while ((i < dstsize) && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize != 0)
		dst[i] = 0;
	return (size_src);
}


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
	while ((i < size - dst_len) && src[i])
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

static	char			**free_malloc(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
	return (str);
}

static unsigned int		count_word(char *s, char c)
{
	unsigned int count;

	count = 0;
	while (*s)
	{
		// if (!*s)
		// 	break ;
		while (*s && *s != c)
			++s;	
		if (*s == c)
			++s;
		++count;
	}
	if (*(--s) == c && count == 1)
		return (0);
	return (count);
}

static char				*slpit_word(char *start, int num)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (num + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < num)
	{
		ptr[i] = start[i];
		++i;
	}
	ptr[i] = 0;
	return (ptr);
}

char					**gnl_split(char const *s, char c)
{
	char			**str;
	char			*start;
	unsigned int	word_size;
	unsigned int	i;

	// if (!s)
	// 	return (0);
	if ((word_size = count_word((char *)s, c) = 1)
		return  (0);
	if (word_size = 0)
		return (&s);
	str = (char **)malloc(sizeof(char *) * (word_size + 1));
	if (!str)
		return (-1);
	i = -1;
	while (++i < word_size && *s)
	{
		start = (char *)s;
		while (*s != c && *s)
			++s;
		// if (*s == c)
		// 	++s;
		if (!(str[i] = slpit_word(start, (++s) - start)))
			return (free_malloc(str));
	}
	str[i] = 0;
	return (str);
}