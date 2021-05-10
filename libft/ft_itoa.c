/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:23:40 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 16:50:52 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ret;
	int		len_ret;
	int		sign;
	int		num;

	len_ret = 1;
	while (num /= 10)
		++len_ret;
	sign = (n > 0) ? 0 : 1;
	ret = (char *)malloc(sizeof(char) * (len_ret + sign + 1));
	if (!ret)
		return (0);
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (--len_ret)
	{
		ret[len_ret + sign] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
