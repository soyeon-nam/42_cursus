/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:56:13 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 16:15:03 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	*str;
	unsigned int	i;
	unsigned int	len_mal;

	len_mal = size * count;
	str = (void*)malloc(len_mal);
	if (!str)
		return (0);
	i = 0;
	while (i < len_mal)
	{
		*str = 0;
		str++;
		++i;
	}
	str -= len_mal;
	return (str);
}

/*
count : malloc할 개체의 수
size : malloc 할 개체의 크기

void * : 0을 초기화한 주소반환
*/


/*
위 에러는 '식이 완전한 개체 형식의 포인터여야 합니다'라고 컴파일 오류를 낸다. '타입체크 에러'로 분류되는 것 같다
https://noel-embedded.tistory.com/1227?category=791177


리턴형이 void*(void 포인터) ??
https://dsnight.tistory.com/51
 */