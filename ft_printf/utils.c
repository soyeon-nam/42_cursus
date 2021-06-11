/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:33:32 by snam              #+#    #+#             */
/*   Updated: 2021/06/11 12:08:49 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern type_ft		g_tag;
extern int			ret_print;

size_t		ft_strlen(const char* s)
{
	size_t	ret;

	if (!s)
		return (0);
	ret = 0;
	while (*s++)
		++ret;
	return (ret);
}

static void		print(long long nb)
{
	char a;

	a = nb % 10 + 48;
	nb = nb / 10;
	if (nb > 0)
		print(nb);
	write(1, &a, 1);
	ret_print++;
}

void			ft_putnbr(long long nb)
{
	if (nb == 0 && g_tag.precision == 0) //&& g_tag.width != 0
	{
		if (g_tag.width <= 0)
			return;
		write(1, " ", 1);
		ret_print++;
		return ;
	}
	// if (nb == -2147483648)
	// 	write(1, "-2147483648", 11);
	// else if (nb < 0)
	// {
	// 	nb *= -1;
	// 	write(1, "-", 1);
	// 	print(nb);
	// }
	//else
	print(nb);
}

