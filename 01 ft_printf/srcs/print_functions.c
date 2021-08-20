/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:50:42 by snam              #+#    #+#             */
/*   Updated: 2021/08/19 04:34:30 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_format_tag *tag)
{
	write(1, &c, 1);
	tag->total_printed_letter_cnt++;
}

void	ft_multiple_putchar(int num, char c, t_format_tag *tag)
{
	while (num-- > 0)
	{
		write(1, &c, 1);
		tag->total_printed_letter_cnt++;
	}
}

void	ft_putnbr(long long nb, t_format_tag *tag)
{
	char	a;

	if (nb == 0 && tag->precision == 0)
	{
		if (tag->width <= 0)
			return ;
		ft_putchar(' ', tag);
		return ;
	}
	a = nb % 10 + 48;
	nb = nb / 10;
	if (nb > 0)
		ft_putnbr(nb, tag);
	ft_putchar(a, tag);
}

void	print_base_upper(long nb, t_format_tag *tag)
{
	int				i;
	static char		g_base_upper[16] = {'0', '1', '2', '3', '4',
										'5', '6', '7', '8', '9',
										'A', 'B', 'C', 'D', 'E', 'F'};

	if (nb == 0 && tag->precision == 0)
		return ;
	i = nb % 16;
	nb /= 16;
	if (nb > 0)
		print_base_upper(nb, tag);
	write(1, &g_base_upper[i], 1);
	tag->total_printed_letter_cnt++;
}

void	print_base_lower(long nb, t_format_tag *tag)
{
	int				i;
	static char		g_base_lower[16] = {'0', '1', '2', '3', '4',
										'5', '6', '7', '8', '9',
										'a', 'b', 'c', 'd', 'e', 'f'};

	if (nb == 0 && tag->precision == 0)
		return ;
	i = nb % 16;
	nb /= 16;
	if (nb > 0)
		print_base_lower(nb, tag);
	write(1, &g_base_lower[i], 1);
	tag->total_printed_letter_cnt++;
}
