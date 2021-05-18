/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:07:51 by snam              #+#    #+#             */
/*   Updated: 2021/05/18 23:09:06 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	void	*ret;

	if (!dst && !src)
		return (0);
	ret = dst;
	while (n--)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		++dst;
		++src;
	}
	return (ret);
}
