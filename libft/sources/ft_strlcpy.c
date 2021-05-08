/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:00:55 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 15:01:18 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	size_src;
	unsigned int	i;

	if (!dst)		//!dst 일 경우, NULL 리턴???
		return (0);
	size_src = ft_strlen(src);
	i = 0;
	while ((i + 1 < dstsize) && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize > 0)  // 왜 꼭 제한을 걸어주어야 하나?
		dst[i] = 0;
	return (size_src);
}

/*
src에서 dst로 값을 size길이 만큼 복사
*/
//배열과 문자열은 다름
