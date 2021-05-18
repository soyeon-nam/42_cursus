/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 22:37:05 by snam              #+#    #+#             */
/*   Updated: 2021/05/18 23:12:21 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	temp[n];

	if (!dst && !src)
		return (dst);
	ft_memcpy(temp, src, n);
	ft_memcpy(dst, temp, n);
	return (dst);
}
