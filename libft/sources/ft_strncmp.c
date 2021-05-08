/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:01:35 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 15:01:50 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned int	i;

	i = 0;
	while (str1[i] && (i + 1 < num))
	{
		if (str1[i] != str2[i])
			break ;
		++i;
	}
	return ((unsigned int)str1[i] - (unsigned int)str2[i]);
}

/*
const float* pf1 = &f1;  
//해당주소의 '실제값'은 변경 불가, 포인터의 주소 자체는 변경 가능

float* const pf2 = &f1;  
//간접접근을 통해 '실제값'은 변경 가능, 포인터의 주소 자체 변경 불가
*/
