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

int		is_set(char *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
}

char	*trim_front(char *s1, char *set)
{
	while (is_set(set, *s1))
		++s1;
	return (s1);
}

void	trim_back(char *s1, char *set)
{
	unsigned int	i;

	i = 0;
	while (s1[i])
		++i;
	while (is_set(set, s1[i] && i >= 0))
		--i;
	s1[i + 1] = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	s1 = trim_front((char *)s1, (char *)set);
	trim_back((char *)s1, (char *)set);
	return ((char *)s1);
}

//ㅅㅐ 거