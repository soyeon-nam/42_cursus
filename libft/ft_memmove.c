/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 22:37:05 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 15:13:37 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*temp;

	if (!dst)
		return (0);
	//if (!src || n <= 0)
	//	return (dst);
	temp = (unsigned char *)malloc(n);
	if (!temp)
		return (0);
	ft_memcpy(temp, src, n);
	ft_memcpy(dst, temp, n);
	return (dst);
}
