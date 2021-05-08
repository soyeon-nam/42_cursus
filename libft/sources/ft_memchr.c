/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 23:28:27 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 16:12:13 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == c)
			return (s);
		++s;
	}
	return (0);
}


/* 메모리함수 왜 unsigned char을 사용해야 하는가?

https://rcode.tistory.com/14
https://kldp.org/node/102514
https://blog.naver.com/morpheuz82/130015717491
*/