/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cppc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:50:04 by snam              #+#    #+#             */
/*   Updated: 2021/06/13 11:05:31 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_ft		g_tag;
extern int			g_ret_print;

int			create_c(va_list ap)
{
	char			c;
	int				size;

	size = g_tag.width - 1;
	if (g_tag.width > 0 && g_tag.flag_bar == 0)
		ft_put_affix(&size, ' ');
	c = va_arg(ap, int);
	write(1, &c, 1);
	g_ret_print++;
	if (size > 0)
		ft_put_affix(&size, ' ');
	return (0);
}

int			create_percent(void)
{
	int		size;

	size = g_tag.width - 1;
	if (g_tag.flag_bar == 0 && g_tag.width > 0)
	{
		if (g_tag.flag_bar == 0 && g_tag.flag_zero > 0 && g_tag.width > 0)
			ft_put_affix(&size, '0');
		else
			ft_put_affix(&size, ' ');
	}
	ft_putchar('%');
	if (size > 0)
		ft_put_affix(&size, ' ');
	return (0);
}

int			create_p(va_list ap)
{
	size_t				pointer;
	long long			size;
	long long			size_width;

	pointer = (size_t)va_arg(ap, char *);
	if (pointer == 0 && g_tag.precision == 0)
		size = 0;
	else
		size = count_digit_hex(pointer);
	size_width = (long long)g_tag.width - size - 2;
	if (g_tag.flag_bar == 0 && (size_width >= 0))
		ft_put_affix_p(&size_width, ' ');
	write(1, "0x", 2);
	g_ret_print += 2;
	print_base_lower(pointer, 16);
	if (g_tag.flag_bar != 0 && (size_width >= 0))
		ft_put_affix_p(&size_width, ' ');
	return (0);
}
