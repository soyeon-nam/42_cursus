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

static void		set_print_numbers_s(int *size_width, int *size_precision,
					int size_num, t_format_tag *tag);
static void		print_s(char *str, int size_precision, t_format_tag *tag);

//t_info로 고치기
void	create_s(t_format_tag *tag)
{
	char	*str;
	int		size_width;
	int		size_precision;

	str = va_arg(tag->ap, char *);
	set_print_numbers_s(&size_width, &size_precision, ft_strlen(str), tag);
	if (!str)
	{
		if (size_precision >= 6 || size_precision < 0)
			size_width -= 6;
		else if (0 <= size_precision && size_precision < 6)
			size_width -= size_precision;
	}
	if (tag->flag_bar == 0)
		ft_multiple_putchar(size_width, ' ', tag);
	print_s(str, size_precision, tag);
	if (tag->flag_bar > 0)
		ft_multiple_putchar(size_width, ' ', tag);
}

static void	set_print_numbers_s(int *size_width, int *size_precision,
	int size_num, t_format_tag *tag)
{
	*size_width = tag->width;
	*size_precision = tag->precision;
	if (tag->precision == 0)
		return ;
	else if (tag->precision <= size_num && tag->precision > 0)
		*size_width -= *size_precision;
	else
		*size_width -= size_num;
}

static void	print_s(char *str, int size_precision, t_format_tag *tag)
{
	if (str)
	{
		if (size_precision >= 0)
			while (size_precision-- && *str)
				ft_putchar(*str++, tag);
		else
			while (*str)
				ft_putchar(*str++, tag);
	}
	else
	{
		if (size_precision >= 6 || size_precision < 0)
		{
			tag->total_printed_letter_cnt += 6;
			write(1, "(null)", 6);
		}
		else if (0 <= size_precision && size_precision < 6)
		{
			tag->total_printed_letter_cnt += size_precision;
			write(1, "(null)", size_precision);
		}
	}
}
