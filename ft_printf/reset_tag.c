#include "ft_printf.h"

extern t_ft			g_tag;

void		reset_tag(void)
{
	g_tag.flag_bar = 0;
	g_tag.flag_zero = 0;
	g_tag.width = 0;
	g_tag.precision = -1;
	g_tag.check_minus_width = 0;
}
