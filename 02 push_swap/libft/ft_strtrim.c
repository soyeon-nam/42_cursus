/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:22:51 by snam              #+#    #+#             */
/*   Updated: 2021/05/20 21:36:18 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
}

static char	*trim_front(char *s1, char *set)
{
	while (is_set(set, *s1))
		++s1;
	return (s1);
}

static char	*trim_back(char *s1, char *set)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = s1;
	while (*ret)
		++ret;
	--ret;
	while (is_set(set, *ret) && s1 < ret)
		--ret;
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*start;
	char	*end;
	int		size;

	if (!s1 || !set)
		return (0);
	start = trim_front((char *)s1, (char *)set);
	end = trim_back(start, (char *)set);
	size = end - start + 1;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	ret[size] = 0;
	while (size--)
		ret[size] = start[size];
	return ((char *)ret);
}
