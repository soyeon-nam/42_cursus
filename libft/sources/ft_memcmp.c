/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 23:27:35 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 14:59:45 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		memcmp(const void *s1, const void *s2, size_t n)
{
	while (*(unsigned char *)s1 && --n)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			break ;
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
