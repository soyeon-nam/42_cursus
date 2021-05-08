/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:12:57 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 14:59:13 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void* ft_memccpy(void* dest, const void* src, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char*)dest = *(unsigned char*)src;
		if (*(unsigned char *)dest == (unsigned char)c)
		{
			++(unsigned char *)dest;
			return (dest);
		}
		++(unsigned char *)dest;
		++(unsigned char *)src;
	}
	return (0);
}


void	*ft_memccpy(void *restrict dest, \
const void *restrict src, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		if (*((unsigned char *)dest)++ == (unsigned char)c)
			return (dest);
		++(unsigned char *)src;
	}
	return (0);
}


/*
#include <string.h>

void *memccpy(void *dest, const void *src, int c, size_t n);

 

이 함수는 src에서 dest로 메모리 값을 n만큼 복사하는 것이다. 복사하면서 c를 찾으면 복사를 멈춘다.

만약 메모리 지역이 겹치면 결과를 정의하지 않는다.

 

반환 값

만약 c를 찾으면 c 다음 주소 값을 반환하고, src의 값에서 n만큼 중 c를 찾지 못하면 NULL 값을 반환한다.
*/
