/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:37:37 by snam              #+#    #+#             */
/*   Updated: 2021/06/11 10:36:35 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern type_ft		g_tag;
extern int			ret_print;

void	ft_put_affix(int *num, char c)
{
	
	while ((*num)-- > 0)
	{
		ret_print++;
		write(1, &c, 1);
	}
}

void	ft_put_affix_p(long long *num, char c)
{
	while ((*num)-- > 0)
	{
		ret_print++;
		write(1, &c, 1);
	}
}

int		count_digit(int num)
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

int		count_digit_u(unsigned int num) 
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

int		count_digit_hex(long long num)
{
	int		ret;

	ret = 1;
	while (num /= 16)
		++ret;
	return (ret);
}

int		count_digit_xX(unsigned int num) 
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