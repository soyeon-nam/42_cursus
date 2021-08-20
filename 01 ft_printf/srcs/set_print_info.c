/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_print_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:40:40 by marvin            #+#    #+#             */
/*   Updated: 2021/08/19 04:34:01 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_print_info(t_print_info *info, int size_num, t_format_tag *tag)
{
	info->width_len = tag->width;
	info->precision_len = tag->precision;
	if (tag->precision > (size_num - info->minus))
	{
		info->width_len -= (tag->precision + info->minus);
		info->precision_len -= (size_num - info->minus);
	}
	else if (tag->precision < 0)
	{
		info->width_len -= size_num;
		info->precision_len = -1;
	}
	else
	{
		info->width_len -= size_num;
		info->precision_len = 0;
	}
}
