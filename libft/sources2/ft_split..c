/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split..c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:23:25 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 17:21:01 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_word(char *s, char c)
{
	int count;

	count = 1;
	while (*s)
	{
		if (*s == c)
			++count;
		++s;
	}
	return (count);
}

char	*slpit_word(char *start, int num)
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

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*start;
	int		word_size;
	int		i;

	word_size = count_word(s, c);
	str = (char **)malloc(sizeof(char *) * (word_size + 1));
	if (!str)
		return (0);
	i = 0;
	str[word_size] = 0;
	while (i < word_size)
	{
		start = s;
		while (*s != c)
			++s;
		str[i] = slpit_word(start, s - start);
		++i;
	}
	str[i] = 0;
	return (str);
}
