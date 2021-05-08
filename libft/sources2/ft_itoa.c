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
	char	*result;
	int		len_result;
	int		sign;
	int		num;

	len_result = 1;
	while (num /= 10)
		++len_result;
	sign = (n > 0) ? 0 : 1;
	result = (char *)malloc(sizeof(char) * (len_result + sign + 1));
	if (!result)
		return (0);
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (--len_result)
	{
		result[len_result + sign] = n % 10;
		n /= 10;
	}
	return (result);
}
