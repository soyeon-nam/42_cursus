#include "ft_printf.h"

extern type_ft		g_tag;
extern int			ret_print;

void	print_base_upper(long nb, int base_num)
{
	int i;
	static char base_upper[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	if (nb == 0 && g_tag.precision == 0)
		return;
	i = nb % base_num;
	if (nb /= base_num)
    	print_base_upper(nb, base_num);
	write(1, &base_upper[i], 1);
	ret_print++;
 }

void	print_base_upper_x(unsigned int nb, int base_num)
{
	int i;
	static char base_upper[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	
	if (nb == 0 && g_tag.precision == 0)
		return;
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
void	print_base_lower_x(unsigned int nb, int base_num)
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