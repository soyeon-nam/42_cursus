#include "ft_printf.h"

extern t_ft		g_tag;
extern int			g_ret_print;

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

