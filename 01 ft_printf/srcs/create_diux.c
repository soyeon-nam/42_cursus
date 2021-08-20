/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_diux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:03:04 by snam              #+#    #+#             */
/*   Updated: 2021/08/19 04:33:44 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		create_di_prefix(t_print_info *info, t_format_tag *tag);

void	create_di(t_format_tag *tag)
{
	long long		num;
	t_print_info	info;

	num = va_arg(tag->ap, int);
	info.minus = 0;
	if (num < 0)
		info.minus = 1;
	set_print_info(&info, count_digit(num), tag);
	if (num < 0)
		num = -num;
	create_di_prefix(&info, tag);
	ft_putnbr(num, tag);
	if (tag->flag_bar > 0)
		ft_multiple_putchar(info.width_len, ' ', tag);
}

static void	create_di_prefix(t_print_info *info, t_format_tag *tag)
{
	if (tag->flag_bar == 0)
	{
		if (tag->flag_zero > 0 && info->precision_len < 0)
		{
			if (info->minus)
				ft_putchar('-', tag);
			ft_multiple_putchar(info->width_len, '0', tag);
		}
		else
		{
			ft_multiple_putchar(info->width_len, ' ', tag);
			if (info->minus)
				ft_putchar('-', tag);
		}
	}
	if (tag->flag_bar != 0 && info->minus)
		ft_putchar('-', tag);
	if (tag->precision >= 0)
		ft_multiple_putchar(info->precision_len, '0', tag);
}

void	create_u(t_format_tag *tag)
{
	unsigned int		num;
	t_print_info		info;

	num = va_arg(tag->ap, unsigned int);
	info.minus = 0;
	set_print_info(&info, count_digit_u(num), tag);
	if (tag->flag_bar == 0 && info.width_len > 0)
	{
		if (tag->flag_zero > 0 && tag->precision < 0)
			ft_multiple_putchar(info.width_len, '0', tag);
		else
			ft_multiple_putchar(info.width_len, ' ', tag);
	}
	if (num < 0)
		ft_putchar('-', tag);
	if (tag->precision >= 0)
		ft_multiple_putchar(info.precision_len, '0', tag);
	ft_putnbr(num, tag);
	if (tag->flag_bar != 0)
		ft_multiple_putchar(info.width_len, ' ', tag);
}

void	create_x(char mode, t_format_tag *tag)
{
	unsigned int		num;
	t_print_info		info;

	num = va_arg(tag->ap, unsigned int);
	info.minus = 0;
	set_print_info(&info, count_digit_hex(num), tag);
	if (tag->precision == 0 && num == 0)
		(info.width_len)++;
	if (tag->flag_bar == 0)
	{
		if (tag->flag_zero > 0 && info.precision_len < 0)
			ft_multiple_putchar(info.width_len, '0', tag);
		else
			ft_multiple_putchar(info.width_len, ' ', tag);
	}
	if (tag->precision >= 0)
		ft_multiple_putchar(info.precision_len, '0', tag);
	if (mode == 'x')
		print_base_lower(num, tag);
	else
		print_base_upper(num, tag);
	if (tag->flag_bar > 0)
		ft_multiple_putchar(info.width_len, ' ', tag);
}
