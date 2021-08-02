/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:44 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:00:45 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
//#include "libft.h"

static char	**free_malloc(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (0);
}

static unsigned int	count_word(char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (!*s)
			break ;
		while (*s && *s != c)
			++s;
		++count;
	}
	return (count);
}

static char	*slpit_word(char *start, int num)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (num + 1));
	if (!ptr)
		return (0);
	i = -1;
	while (++i < num)
		ptr[i] = start[i];
	ptr[i] = 0;
	return (ptr);
}

char					**ft_split(char const *s, char c)
{
	char			**str;
	char			*start;
	unsigned int	word_size;
	unsigned int	i;

	if (!s)
		return (0);
	word_size = count_word((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (word_size + 1));
	if (!str)
		return (0);
	i = -1;
	while (++i < word_size)
	{
		while (*s == c)
			++s;
		start = (char *)s;
		while (*s != c && *s)
			++s;
		str[i] = slpit_word(start, s - start);
		if (!str[i])
			return (free_malloc(str));
	}
	str[i] = 0;
	return (str);
}
