/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cppc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:50:04 by snam              #+#    #+#             */
/*   Updated: 2021/08/19 04:33:40 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_c(t_format_tag *tag)
{
	char		c;
	int			size;

	c = va_arg(tag->ap, int);
	size = tag->width - 1;
	if (tag->flag_bar == 0 && size > 0)
		ft_multiple_putchar(size, ' ', tag);
	ft_putchar(c, tag);
	if (tag->flag_bar != 0 && size > 0)
		ft_multiple_putchar(size, ' ', tag);
}

void	create_percent(t_format_tag *tag)
{
	int			size;

	size = tag->width - 1;
	if (tag->flag_bar == 0 && size > 0)
	{
		if (tag->flag_zero > 0)
			ft_multiple_putchar(size, '0', tag);
		else
			ft_multiple_putchar(size, ' ', tag);
	}
	ft_putchar('%', tag);
	if (tag->flag_bar != 0 && size > 0)
		ft_multiple_putchar(size, ' ', tag);
}

void	create_p(t_format_tag *tag)
{
	size_t		pointer;
	int			size;
	int			size_width;

	pointer = (size_t)va_arg(tag->ap, char *);
	if (pointer == 0 && tag->precision == 0)
		size = 0;
	else
		size = count_digit_hex(pointer);
	size_width = tag->width - size - 2;
	if (tag->flag_bar == 0 && size_width > 0)
		ft_multiple_putchar(size_width, ' ', tag);
	write(1, "0x", 2);
	tag->total_printed_letter_cnt += 2;
	print_base_lower(pointer, tag);
	if (tag->flag_bar != 0 && size_width > 0)
		ft_multiple_putchar(size_width, ' ', tag);
}
