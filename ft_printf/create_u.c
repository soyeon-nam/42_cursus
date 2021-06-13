/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 22:50:43 by snam              #+#    #+#             */
/*   Updated: 2021/06/13 10:53:12 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_ft		g_tag;
extern int			g_ret_print;

int			create_u(va_list ap)
{
	unsigned int		num;
	int					size_width;
	int					size_precision;
	int					size_num;
	int					minus_flag;

	num = va_arg(ap, unsigned int);
	size_num = count_digit_u(num);
	minus_flag = (num < 0 ? 1 : 0);
	set_print_numbers_u(&size_width, &size_precision, size_num, num);
	if (g_tag.flag_bar == 0)
	{
		if (g_tag.flag_zero > 0 && g_tag.precision < 0)
			ft_put_affix(&size_width, '0');
		else
			ft_put_affix(&size_width, ' ');
	}
	if (g_tag.flag_bar != 0 && minus_flag)
		ft_putchar('-');
	if (g_tag.precision >= 0)
		ft_put_affix(&size_precision, '0');
	ft_putnbr(num);
	if (g_tag.flag_bar > 0)
		ft_put_affix(&size_width, ' ');
	return (0);
}

void		set_print_numbers_u(int *size_width,
							int *size_precision, int size_num, size_t num)
{
	*size_width = g_tag.width;
	*size_precision = g_tag.precision;
	if (num < 0)
		set_print_numbers_negative(size_width, size_precision, size_num);
	else
		set_print_numbers_positive(size_width, size_precision, size_num);
}
