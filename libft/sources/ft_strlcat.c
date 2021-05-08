/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:00:50 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 15:00:51 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		dst_len;
	int		src_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (!size)
		return (src_len);
	if ((size <= dst_len) || dst_len)
		return (src_len + size);
	while ((i < size - dst_len - 1) && src[i])
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

/*
i < size - dst_len - 1
여기서 i는 int형이고, 그러면 r-value는 어떤 자료형이 되는 것??
첫번째의 size 기준으로 만들어지는 것인가?
*/