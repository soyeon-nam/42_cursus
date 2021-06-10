/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tocken.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:33:26 by snam              #+#    #+#             */
/*   Updated: 2021/06/10 15:51:05 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern type_ft		g_tag;

void	process_bar(int state)
{
	if (state == 2)
		++g_tag.flag_bar;
}

void	process_zero(int state, char input)
{
	if (state == 2)
		++g_tag.flag_zero;
	else if (state == 3)
		update_num(input, 0);
	else if (state == 6)
		update_num(input, 1);
}

void	process_asterisk(int state, va_list ap)
{
	int		num;

	num = va_arg(ap, int);
	if (state == 2)
	{
		if (num < 0) 
		{
			++g_tag.flag_bar;
			g_tag.check_minus_width = 1;
			g_tag.flag_zero = 0;
		}
		g_tag.width = (num > 0 ? num : -num);
	}
	else if (state == 5)
	{
		if (num < 0) //num <=0
			g_tag.precision = -1;
		else
			g_tag.precision = num;
	}
}

void		process_one_to_nine(int state, char input)
{
	if (state == 2 || state == 3)
		update_num(input, 0);
	else if (state == 5 || state == 6)
		update_num(input, 1);
}

void		process_dot(int state)
{
	if (state == 2 || state == 3 || state == 4)
		g_tag.precision = 0;
}