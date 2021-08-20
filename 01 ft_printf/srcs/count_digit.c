/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:37:37 by snam              #+#    #+#             */
/*   Updated: 2021/08/19 04:33:32 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>

int	count_digit(int num)
{
	int		ret;

	ret = 1;
	if (num < 0)
		++ret;
	num /= 10;
	while (num)
	{
		++ret;
		num /= 10;
	}
	return (ret);
}

int	count_digit_u(unsigned int num)
{
	int		ret;

	ret = 1;
	num /= 10;
	while (num > 0)
	{
		num /= 10;
		++ret;
	}
	return (ret);
}

int	count_digit_hex(size_t num)
{
	int		ret;

	ret = 1;
	num /= 16;
	while (num > 0)
	{
		num /= 16;
		++ret;
	}
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	ret;

	if (!s)
		return (0);
	ret = 0;
	while (*s++)
		++ret;
	return (ret);
}
