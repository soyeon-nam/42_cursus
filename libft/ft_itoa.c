/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:23:40 by snam              #+#    #+#             */
/*   Updated: 2021/05/18 22:43:51 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n)
{
	char	*ret;
	int		len_ret;
	int		sign;
	long	num;

	len_ret = 1;
	num = n;
	n = (n >= 0) ? num : -num;
	while (n /= 10)
		++len_ret;
	sign = (num >= 0) ? 0 : 1;
	if (!(ret = (char *)malloc(sizeof(char) * (len_ret + sign + 1))))
		return (0);
	if (num < 0)
	{
		ret[0] = '-';
		num *= -1;
	}
	ret[len_ret + sign] = 0;
	while (--len_ret >= 0)
	{
		ret[len_ret + sign] = (num % 10) + '0';
		num /= 10;
	}
	return (ret);
}
