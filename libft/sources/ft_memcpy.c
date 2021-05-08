/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:07:51 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 14:59:59 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	void	*dest_ptr;

	dest_ptr = dest;
	while (n--)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		++(unsigned char *)dest;
		++(unsigned char *)src;
	}
	return (dest_ptr);
}

/*
첫번째 인자 void* dest
= 복사 받을 메모리를 가리키는 포인터

두번째 인자 const void* source
= 복사할 메모리를 가리키고 있는 포인터

세번째 인자 size_t num
= 복사할 데이터(값)의 길이(바이트 단위)

*/
