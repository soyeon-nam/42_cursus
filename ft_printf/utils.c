/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:33:32 by snam              #+#    #+#             */
/*   Updated: 2021/06/13 10:53:12 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_ft		g_tag;
extern int			g_ret_print;

size_t			ft_strlen(const char *s)
{
	size_t	ret;

	if (!s)
		return (0);
	ret = 0;
	while (*s++)
		++ret;
	return (ret);
}

static void		ft_putnbr_print(long long nb)
{
	char a;

	a = nb % 10 + 48;
	nb = nb / 10;
	if (nb > 0)
		ft_putnbr_print(nb);
	write(1, &a, 1);
	g_ret_print++;
}

void			ft_putnbr(long long nb)
{
	if (nb == 0 && g_tag.precision == 0)
	{
		if (g_tag.width <= 0)
			return ;
		write(1, " ", 1);
		g_ret_print++;
		return ;
	}
	ft_putnbr_print(nb);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
	g_ret_print++;
}
