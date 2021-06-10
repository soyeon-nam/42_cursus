/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:33:32 by snam              #+#    #+#             */
/*   Updated: 2021/06/10 16:30:58 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern type_ft		g_tag;
extern int			ret_print;

void		update_num(char c, int mode)  //업데이트 시켜서 숫자 저장하는 함수  //mode 1: width mode : precision
{
	if (mode == 0)
	{
		g_tag.width *= 10;
		g_tag.width += (c - '0');
	}
	else
	{
		g_tag.precision *= 10;
		g_tag.precision += (c - '0');
	}
}

void		reset_tag()
{
	g_tag.flag_bar = 0; 
	g_tag.flag_zero = 0;
	g_tag.width = 0;
	g_tag.precision = -1;
	g_tag.check_minus_width = 0;

}

void	ft_put_affix(long long *num, char c)
{
	while ((*num)-- > 0)
	{
		ret_print++;
		write(1, &c, 1);
	}
}

int		count_digit(int num)
{
	int		ret;

	ret = 1;
	if (ret < 0)
	{
		++ret;
		ret *= -1;
	}
	while (num /= 10)
		++ret;
	return (ret);
}

int		count_digit_hex(long long num)
{
	int		ret;

	ret = 1;
	while (num /= 16)
		++ret;
	return (ret);
}

size_t		ft_strlen(const char* s)
{
	size_t	ret;

	if (!s)
		return (0);
	ret = 0;
	while (s[ret])
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

void	print_base_upper(long nb, int base_num)
{
	int i;
	static char base_upper[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	i = nb % base_num;
	if (nb /= base_num)
    	print_base_upper(nb, base_num);
	write(1, &base_upper[i], 1);
	ret_print++;
 }

void	print_base_lower(long nb, int base_num)
{
	int i;
	static char base_lower[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

	if (nb == 0 && g_tag.precision == 0)
		return;
	i = nb % base_num;
	if (nb /= base_num)
    	print_base_lower(nb, base_num);
	write(1, &base_lower[i], 1);
	ret_print++;
}
