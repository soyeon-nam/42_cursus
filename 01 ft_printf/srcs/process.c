/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:33:56 by snam              #+#    #+#             */
/*   Updated: 2021/08/19 04:33:56 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_2(char input, t_format_tag *tag)
{
	if (input == '-')
		tag->flag_bar = 1;
	else if (input == '0')
		tag->flag_zero = 1;
}

void	process_4(t_format_tag *tag)
{
	int		num;

	num = va_arg(tag->ap, int);
	if (num < 0)
	{
		++tag->flag_bar;
		tag->flag_zero = 0;
	}
	if (num >= 0)
		tag->width = num;
	else
		tag->width = -num;
}

void	process_7(t_format_tag *tag)
{
	int		num;

	num = va_arg(tag->ap, int);
	if (num < 0)
		tag->precision = -1;
	else
		tag->precision = num;
}

void	process_8(char spec, t_format_tag *tag)
{
	if (spec == 'c')
		create_c(tag);
	else if (spec == 's')
		create_s(tag);
	else if (spec == 'p')
		create_p(tag);
	else if (spec == '%')
		create_percent(tag);
	else if (spec == 'd')
		create_di(tag);
	else if (spec == 'i')
		create_di(tag);
	else if (spec == 'u')
		create_u(tag);
	else if (spec == 'x')
		create_x('x', tag);
	else if (spec == 'X')
		create_x('X', tag);
	reset_tag(tag);
}
