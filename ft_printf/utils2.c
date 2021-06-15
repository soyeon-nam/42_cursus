/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:22:57 by snam              #+#    #+#             */
/*   Updated: 2021/06/14 19:51:06 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_ft		g_tag;
extern int			g_ret_print;

void		ft_put_affix(int *num, char c)
{
	while ((*num)-- > 0)
	{
		g_ret_print++;
		write(1, &c, 1);
	}
}

void		update_width(char c)
{
	g_tag.width *= 10;
	g_tag.width += (c - '0');
}

void		update_precision(char c)
{
	g_tag.precision *= 10;
	g_tag.precision += (c - '0');
}

// void		update_nbr(int *num, char c)
// {
// 	*num *= 10;
// 	*num += (c - '0');
// }

void		reset_tag(void)
{
	g_tag.flag_bar = 0;
	g_tag.flag_zero = 0;
	g_tag.width = 0;
	g_tag.precision = -1;
	g_tag.check_minus_width = 0;
}
