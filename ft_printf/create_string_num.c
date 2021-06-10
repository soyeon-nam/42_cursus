/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_string_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:33:30 by snam              #+#    #+#             */
/*   Updated: 2021/06/10 22:37:03 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ft_printf.h"

extern type_ft		g_tag;
extern int			ret_print;

void	set_print_numbers_di(long long *size_width, long long *size_precision, long long size_num, int num)
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


void		set_print_numbers_s(long long *size_width, long long *size_precision, long long size_num)
{
	*size_width = g_tag.width;
	*size_precision = g_tag.precision;
	if (g_tag.precision == 0)
		return ;
	else if (g_tag.precision <= size_num && g_tag.precision > 0)
		*size_width -= *size_precision;
	else
		*size_width -= size_num;
}

int		create_di(va_list ap)
{
	long long		num;
	long long		size_width;
	long long		size_precision;
	long long		size_num;
	int		minus_flag;
	
	num = va_arg(ap, int);
	size_num = count_digit(num);
	minus_flag = (num < 0 ? 1 : 0);
	set_print_numbers_di(&size_width, &size_precision, size_num, num);
	num = (num < 0 ? -num : num);

	if (g_tag.flag_bar == 0)
	{
		//printf("%d %lld\n", g_tag.flag_zero, size_precision);
		if (g_tag.flag_zero > 0 && size_precision < 0)
		{
			if (minus_flag)
			{
				ret_print++;
				write(1, "-", 1);
			}
			ft_put_affix(&size_width, '0');
		}
		else
		{
			ft_put_affix(&size_width, ' ');
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
	if (g_tag.precision >= 0)
		ft_put_affix(&size_precision, '0');
	ft_putnbr(num);
	if (g_tag.flag_bar > 0)
		ft_put_affix(&size_width, ' ');	
	return (0);
}


int		create_u(va_list ap)
{
	long long		num;
	long long		size_width;
	long long		size_precision;
	long long		size_num;
	int		minus_flag;
	
	// if (g_tag.flag_zero > 0 && g_tag.flag_bar > 0)
	// 	return (-1);
	num = va_arg(ap, int);
	size_num = count_digit(num);
	minus_flag = (num < 0 ? 1 : 0);
	set_print_numbers_di(&size_width, &size_precision, size_num, num);
	num = (num < 0 ? -num : num);

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

// int		create_u(va_list ap)
// {
// 	unsigned int num;

// 	num = va_arg(ap, int);


// 	return (0);
	

int		create_x(va_list ap)
{
	unsigned int num;

	num = va_arg(ap, int);


	return (0);
}

int		create_X(va_list ap)
{
	unsigned int num;

	num = va_arg(ap, int);


	return (0);
}
