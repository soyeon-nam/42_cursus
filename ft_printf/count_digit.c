/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:37:37 by snam              #+#    #+#             */
/*   Updated: 2021/06/14 19:34:11 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_digit(int num)
{
	int		ret;

	ret = 1;
	if (ret < 0)
	{
		++ret;
		ret *= -1;
	}
	while (num /= 10)
		++ret;
	return (ret);
}

int			count_digit_u(unsigned int num)
{
	int		ret;

	ret = 1;
	if (ret < 0)
	{
		++ret;
		ret *= -1;
	}
	while (num /= 10)
		++ret;
	return (ret);
}

int			count_digit_hex(size_t num)
{
	int		ret;

	ret = 1;
	while (num /= 16)
		++ret;
	return (ret);
}

int			count_digit_x(unsigned int num)
{
	int		ret;

	ret = 1;
	if (ret < 0)
	{
		++ret;
		ret *= -1;
	}
	while (num /= 16)
		++ret;
	return (ret);
}
