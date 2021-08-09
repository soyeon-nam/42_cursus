/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 02:21:22 by marvin            #+#    #+#             */
/*   Updated: 2021/05/20 16:13:38 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t		to_find_len;

	if (!*to_find)
		return ((char *)str);
	to_find_len = ft_strlen(to_find);
	if (ft_strlen((char *)str) < to_find_len || n < to_find_len)
		return (0);
	while ((n - to_find_len + 1) && *str)
	{
		if (ft_strncmp(str, to_find, to_find_len) == 0)
			return ((char *)str);
		--n;
		++str;
	}
	return (0);
}
