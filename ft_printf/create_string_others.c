/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_string_others.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:50:04 by snam              #+#    #+#             */
/*   Updated: 2021/06/10 22:38:30 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern type_ft		g_tag;
extern int			ret_print;

//	printf("%d %d %d %d", g_tag.flag_bar, g_tag.flag_zero, g_tag.flag_zero, g_tag.precision);

int			create_string(char spec, va_list ap)
{
	int		ret;

	ret = -1;
	if (spec == 'c')
		ret = create_c(ap);
	else if (spec == 's')
		ret = create_s(ap);
	else if (spec == 'p')
		ret = create_p(ap);
	else if (spec == '%')
		ret = create_percent();
	else if (spec == 'd' || spec == 'i')
		ret = create_di(ap);
	else if (spec == 'u')
		ret = create_u(ap);
	else if (spec == 'x')
		ret = create_x(ap);
	else if (spec == 'X')
		ret = create_X(ap);
	reset_tag();
	return (ret);
}

int			create_c(va_list ap)
{
	char 	c;
	long long		size;

	size = g_tag.width - 1;
	if (g_tag.width > 0 && g_tag.flag_bar == 0)
		ft_put_affix(&size, ' ');
	c = va_arg(ap, int);
	write(1, &c, 1);
	ret_print++;
	if (size > 0)
		ft_put_affix(&size, ' ');
	return (0);
}

int		create_s(va_list ap)
{
	char			*str;
	long long		size_width;
	long long		size_precision;
	long long		size_num;
	// int				num;

	// if (g_tag.flag_zero > 0)
	// 	return (-1);
	str = va_arg(ap, char *);
	size_num = ft_strlen(str);
	set_print_numbers_s(&size_width, &size_precision, size_num);
	if (!str)
	{
		if (size_precision >= 6 || size_precision < 0) 
			size_width -= 6;
		else if (0 <= size_precision && size_precision < 6)
			size_width -= size_precision; 
	}
	if (g_tag.flag_bar == 0)
		ft_put_affix(&size_width, ' ');
	size_num = size_precision;
	if (str)
	{
		if (size_precision >= 0)
			while (size_precision-- && *str)
			{
				ret_print++;
				write(1, str++, 1);
			}
		else
			while (*str)
			{
				ret_print++;
				write(1, str++, 1);
			}
	}
	else 
	{
		if (size_precision >= 6 || size_precision < 0)
		{	
			ret_print += 6;
			write(1, "(null)", 6);
		}
		else if (0 <= size_precision && size_precision < 6)
		{	
			ret_print += size_precision;
			write(1, "(null)", size_precision);
		}
	}
	if (g_tag.flag_bar > 0)
		ft_put_affix(&size_width, ' ');
	return (0);
}

int		create_p(va_list ap)
{
	size_t				pointer;
	long long		size;
	long long		size_width;

	pointer = (size_t)va_arg(ap, char *);

	if (pointer == 0 && g_tag.precision == 0)
		size = 0;
	else
		size = count_digit_hex(pointer);
	size_width = (long long)g_tag.width - size - 2;
	if (g_tag.flag_bar == 0 && size_width >=0)
		ft_put_affix(&size_width, ' ');
	write(1, "0x", 2);
	ret_print += 2;
	print_base_lower(pointer, 16);
	if (g_tag.flag_bar != 0 && size_width >=0)
		ft_put_affix(&size_width, ' ');
	return (0);
}

int		create_percent()
{
	long long		size;

	size = g_tag.width - 1;
	if (g_tag.flag_bar == 0 && g_tag.width > 0)
	{
		if (g_tag.flag_bar == 0 && g_tag.flag_zero > 0 && g_tag.width > 0)
			ft_put_affix(&size, '0');
		else
			ft_put_affix(&size, ' ');
	}
	write(1, "%%", 1);
	ret_print++;
	if (size > 0)
		ft_put_affix(&size, ' ');
	return (0);
}
