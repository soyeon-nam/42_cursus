/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:22:51 by snam              #+#    #+#             */
/*   Updated: 2021/05/18 22:47:57 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_set(char *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
}

static char		*trim_front(char *s1, char *set)
{
	while (is_set(set, *s1))
		++s1;
	return (s1);
}

static char		*trim_back(char *s1, char *set)
{
	unsigned int	i;

	i = 0;
	while (s1[i])
		++i;
	while (is_set(set, s1[i] && i >= 0))
		--i;
	return (&s1[i]);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*start;
	char	*end;
	int		size;

	start = trim_front((char *)s1, (char *)set);
	end = trim_back(start, (char *)set);
	size = start - end + 1;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	ret[size] = 0;
	while (size--)
		ret[size] = start[size]; 
	return ((char *)ret);
}
