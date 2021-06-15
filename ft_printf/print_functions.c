#include "ft_printf.h"

extern t_ft			g_tag;
extern int			g_ret_print;

void			ft_putchar(char c)
{
	write(1, &c, 1);
	g_ret_print++;
}

void			ft_put_affix(int *num, char c)
{
	while ((*num)-- > 0)
	{
		g_ret_print++;
		write(1, &c, 1);
	}
}

static void		ft_putnbr_print(long long nb)
{
	char 	a;

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
