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

static void	stack_number(char *ret, long num, int len, int sign)
{
	if (num < 0)
	{
		ret[0] = '-';
		num *= -1;
	}
	ret[len + sign] = 0;
	while (--len >= 0)
	{
		ret[len + sign] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		sign;
	long	num;

	len = 1;
	num = n;
	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	n /= 10;
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	ret = (char *)malloc(sizeof(char) * (len + sign + 1));
	if (!ret)
		return (0);
	stack_number(ret, num, len, sign);
	return (ret);
}
