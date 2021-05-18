/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:01:35 by snam              #+#    #+#             */
/*   Updated: 2021/05/18 20:21:36 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned int	i;

	if (num == 0)
		return (0);
	i = 0;
	while (str1[i] && (i + 1 < num))
	{
		if (str1[i] != str2[i])
			break ;
		++i;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
