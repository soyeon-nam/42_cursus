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
	unsigned int	*ret;
	unsigned int	len_mal;

	len_mal = size * count;
	ret = (void *)malloc(len_mal);
	if (!ret)
		return (0);
	ft_bzero(ret, len_mal);
	return (ret);
}
