/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:24:47 by snam              #+#    #+#             */
/*   Updated: 2021/06/13 10:53:12 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_ft		g_tag;
extern int			g_ret_print;
static char			g_base_upper[16] =
{'0', '1', '2', '3', '4',
	'5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F'};
static char			g_base_lower[16] =
{'0', '1', '2', '3', '4',
	'5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f'};

void		print_base_upper(long nb, int base_num)
{
	int i;

	if (nb == 0 && g_tag.precision == 0)
		return ;
	i = nb % base_num;
	if (nb /= base_num)
		print_base_upper(nb, base_num);
	write(1, &g_base_upper[i], 1);
	g_ret_print++;
}

void		print_base_lower(long nb, int base_num)
{
	int i;

	if (nb == 0 && g_tag.precision == 0)
		return ;
	i = nb % base_num;
	if (nb /= base_num)
		print_base_lower(nb, base_num);
	write(1, &g_base_lower[i], 1);
	g_ret_print++;
}

void		print_base_upper_x(unsigned int nb, int base_num)
{
	int i;

	if (nb == 0 && g_tag.precision == 0)
		return ;
	i = nb % base_num;
	if (nb /= base_num)
		print_base_upper(nb, base_num);
	write(1, &g_base_upper[i], 1);
	g_ret_print++;
}

void		print_base_lower_x(unsigned int nb, int base_num)
{
	int i;

	if (nb == 0 && g_tag.precision == 0)
		return ;
	i = nb % base_num;
	if (nb /= base_num)
		print_base_lower(nb, base_num);
	write(1, &g_base_lower[i], 1);
	g_ret_print++;
}
