/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 22:50:43 by snam              #+#    #+#             */
/*   Updated: 2021/06/11 10:55:43 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern type_ft		g_tag;
extern int			ret_print;

int		create_u(va_list ap)
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
	num = (num < 0 ? -num : num); /*ㅃㅐㄷㅗ ㄷㅗㅣㄴㅡㄴㅈㅣ ㅎㅗㅏㄱㅇㅣㄴ*/
	if (g_tag.flag_bar == 0)
	{
		if (g_tag.flag_zero > 0 && g_tag.precision < 0)
			ft_put_affix(&size_width, '0');
		else
			ft_put_affix(&size_width, ' ');
	}
	if (g_tag.flag_bar != 0 && minus_flag)
	{
		ret_print++;
		write(1, "-", 1);
	}
	if (g_tag.precision >= 0)
		ft_put_affix(&size_precision, '0');
	ft_putnbr(num);
	if (g_tag.flag_bar > 0)
		ft_put_affix(&size_width, ' ');	
	return (0);
}

void	set_print_numbers_u(int *size_width, int *size_precision, int size_num, size_t num)
{
	*size_width = g_tag.width;
	*size_precision = g_tag.precision;
	//printf("%d %d\n", g_tag.width, g_tag.precision);

	if (num < 0)
	{
		if (g_tag.precision > size_num)
		{
			*size_width -= (g_tag.precision + 1);
			*size_precision -= size_num;
		}
		else if (g_tag.precision < 0)
		{
			*size_width -= (size_num + 1);
			*size_precision = -1;
		}
		else 
		{
			*size_width -= (size_num + 1);
			*size_precision = 0;
		}
	}
	else
	{
		if (g_tag.precision > size_num)
		{
			*size_width -= g_tag.precision;
			*size_precision -= size_num;
		}
		else if (g_tag.precision < 0)
		{
			// if (num == 0)
			// 	(*size_width)++;
			*size_width -= size_num;
			*size_precision = -1;
		}
		else
		{
			// if (num == 0)
			// 	(*size_width)++;
			*size_width -= size_num;
			*size_precision = 0;
		}
// printf("\n1: %lld --\n", *size_width);
	}
}

