/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:03:18 by snam              #+#    #+#             */
/*   Updated: 2021/06/11 14:33:37 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ft_printf.h"

extern type_ft		g_tag;
extern int			ret_print;

int		create_xX(char mode, va_list ap)
{
	unsigned int		num;
	int		size_width;
	int		size_precision;
	int		size_num;
	int		minus_flag;

	num = va_arg(ap, unsigned int);
	size_num = count_digit_xX(num);
	minus_flag = (num < 0 ? 1 : 0);
	set_print_numbers_xX(&size_width, &size_precision, size_num, num);
	create__xX_prefix(size_precision, &size_width, minus_flag);
	if (g_tag.precision >= 0)
		ft_put_affix(&size_precision, '0');
	print_xX(mode, num, 16);
	if (g_tag.flag_bar > 0)
		ft_put_affix(&size_width, ' ');	
	return (0);
}

void	set_print_numbers_xX(int *size_width, int *size_precision, int size_num, int num)
{
	*size_width = g_tag.width;
	*size_precision = g_tag.precision;
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
		if (num == 0  && g_tag.precision != 1)////////////
			(*size_width)++;//ㅇㅗㅣㅇㅇ?
		*size_width -= size_num;
		*size_precision = 0;
	}
}

void		create__xX_prefix(int size_precision, int *size_width, int minus_flag)
{
	if (g_tag.flag_bar == 0)
	{
		if (g_tag.flag_zero > 0 && size_precision < 0)
		{
			if (minus_flag)
			{
				ret_print++;
				write(1, "-", 1);
			}
			ft_put_affix(size_width, '0');
		}
		else
		{
			ft_put_affix(size_width, ' ');
			if (minus_flag)
			{
				write(1, "-", 1);
				ret_print++;
			}
		}
	}
	if (g_tag.flag_bar != 0 && minus_flag)
	{
		ret_print++;
		write(1, "-", 1);
	}
}

void	print_xX(char mode, unsigned int nb, int base_num)
{	
	if (mode == 'x')
		print_base_lower_x(nb, base_num);
	else
		print_base_upper_x(nb, base_num);
}