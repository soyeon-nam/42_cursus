/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:03:14 by snam              #+#    #+#             */
/*   Updated: 2021/08/19 04:33:47 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_print_numbers_s(t_print_info *info, \
								char *str, t_format_tag *tag);

void	create_s(t_format_tag *tag)
{	
	char			*str;
	t_print_info	info;

	str = va_arg(tag->ap, char *);
	set_print_numbers_s(&info, str, tag);
	if (tag->flag_bar == 0)
		ft_multiple_putchar(info.width_len, ' ', tag);
	if (str)
	{
		while (info.arg_len--)
			ft_putchar(*str++, tag);
	}
	else
	{
		write(1, "(null)", info.arg_len);
		tag->total_printed_letter_cnt += info.arg_len;
	}
	if (tag->flag_bar != 0)
		ft_multiple_putchar(info.width_len, ' ', tag);
}

static void	set_print_numbers_s(t_print_info *info, \
							char *str, t_format_tag *tag)
{
	info->width_len = tag->width;
	info->precision_len = tag->precision;
	info->arg_len = ft_strlen(str);
	if (!str)
		info->arg_len = 6;
	if (tag->precision > info->arg_len)
	{
		info->width_len -= info->arg_len;
		info->precision_len = -1;
	}
	else if (tag->precision >= 0)
	{
		info->width_len -= info->precision_len;
		info->arg_len = info->precision_len;
	}
	else if (tag->width >= info->arg_len)
		info->width_len -= info->arg_len;
	else
		info->width_len = 0;
}
