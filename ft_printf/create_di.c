/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:03:04 by snam              #+#    #+#             */
/*   Updated: 2021/06/14 20:45:24 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_ft			g_tag;
extern int			g_ret_print;

void			create_di(va_list ap)
{
	long long		num;
	int				size_width;
	int				size_precision;
	int				size_num;
	int				minus_flag;

	num = va_arg(ap, int);
	size_num = count_digit(num);
	minus_flag = (num < 0 ? 1 : 0);
	set_print_numbers_di(&size_width, &size_precision, size_num, num);
	num = (num < 0 ? -num : num);
	create_di_prefix(size_precision, &size_width, minus_flag);
	if (g_tag.precision >= 0)
		ft_put_affix(&size_precision, '0');
	ft_putnbr(num);
	if (g_tag.flag_bar > 0)
		ft_put_affix(&size_width, ' ');
}

void		set_print_numbers_di(int *size_width,
								int *size_precision, int size_num, int num)
{
	*size_width = g_tag.width;
	*size_precision = g_tag.precision;
	if (num < 0)
		set_print_numbers_negative(size_width, size_precision, size_num);
	else
		set_print_numbers_positive(size_width, size_precision, size_num);
}

void		set_print_numbers_negative(int *size_width,
									int *size_precision, int size_num)
{
	if (g_tag.precision > size_num)
	{
		*size_width -= (g_tag.precision + 1);
		*size_precision -= size_num;
	}
	else if (g_tag.precision < 0)
	{
		*size_width -= (size_num + 1);
		*size_precision = -1;
	}
	else
	{
		*size_width -= (size_num + 1);
		*size_precision = 0;
	}
}

// void	set_width_prec(int *size_width, int *size_precision, int size_num)
// {}


void		set_print_numbers_positive(int *size_width,
									int *size_precision, int size_num)
{
	if (g_tag.precision > size_num)
	{
		*size_width -= g_tag.precision;
		*size_precision -= size_num;
	}
	else if (g_tag.precision < 0)
	{
		*size_width -= size_num;
		*size_precision = -1;
	}
	else
	{
		*size_width -= size_num;
		*size_precision = 0;
	}
}

void		create_di_prefix(int size_precision,
							int *size_width, int minus_flag)
{
	if (g_tag.flag_bar == 0)
	{
		if (g_tag.flag_zero > 0 && size_precision < 0)
		{
			if (minus_flag)
				ft_putchar('-');
			ft_put_affix(size_width, '0');
		}
		else
		{
			ft_put_affix(size_width, ' ');
			if (minus_flag)
				ft_putchar('-');
		}
	}
	if (g_tag.flag_bar != 0 && minus_flag)
		ft_putchar('-');
}
