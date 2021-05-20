/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:03:25 by snam              #+#    #+#             */
/*   Updated: 2021/05/20 22:33:43 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_len(char *s, unsigned int start, size_t len)
{
	int		ret;

	ret = 0;
	while (len-- && s[start + ret])
	{
		++ret;
	}
	return (ret);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (0);
	if (len == 0 || (start + 1 > ft_strlen(s)))
	{
		str = (char *)malloc(1);
		*str = 0;
		return (str);
	}
	len = count_len((char *)s, start, len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[start + i] && (i < len))
	{
		str[i] = s[start + i];
		++i;
	}
	str[i] = 0;
	return (str);
}
