/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 02:21:22 by marvin            #+#    #+#             */
/*   Updated: 2021/05/10 02:21:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int		to_find_len;
	int		to_find_idx;
	int		str_idx;

	if (!*to_find)
		return ((char *)str);
	to_find_len =  ft_strlen(to_find);
	if (ft_strlen(str) < to_find_len || n < to_find_len)
		return (0);
	while ((str_idx <= n - to_find_len) && str[str_idx])
	{
		to_find_idx = 0;
		while (str[str_idx++] == to_find[to_find_idx++] && str[str_idx])
		{
			if (to_find_idx == to_find_len)
				return (str[str_idx - to_find_len]);
		}
	}
	return (0);
}
