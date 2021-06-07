#include "printf.h"

void		print_c(char* str, type_head head, va_list ap)
{
	
	if (head.width > 0 && !head.flag_bar)
	{
		if (head.flag_zero)
			ft_put_affix(--head.width, '0');
		else
			ft_put_affix(--head.width, ' ');
	}
	_write(1, &((char)va_arg(ap, int)), 1);
	if (head.width > 0 && head.flag_bar)
		ft_put_affix(--head.width, ' ');
}

int	print_d_i_affix(long long num, type_head head)
{
	int		num_size;

	num_size = count_digit(num);
	if (!head.flag_bar)
	{
		if ((head.width -= num_size) > 0 && (head.precision -= num_size) > 0)
		{
			if (head.precision >= head.width)
				ft_put_affix(head.precision, '0');
			else
			{
				ft_put_affix(head.width - head.precision, ' ');
				ft_put_affix(head.precision, '0');
			}
		}
		else if (head.precision > 0)
			ft_put_affix(head.precision, '0');
		else if (head.width > 0 && head.flag_zero)
			ft_put_affix(head.width, '0');
		else if (head.width > 0)
			ft_put_affix(head.width, ' ');
		return (0);
	}
	else
	{
		if ((head.precision -= num_size) > 0)
			ft_put_affix(head.precision, '0');
		else
			return (head.width -= num_size);
		return ((head.width -= num_size) - head.precision);
	}
}

void		print_d_i(char* str, type_head head, va_list ap)
{
	int				num_size;
	long long		num;
	int		size_left;

	num = (long)va_arg(ap, int);
	size_left = print_d_i_affix(num, head);
	ft_putnbr(num);
	if (size_left > 0)
		ft_put_affix(size_left, ' ');
}



int	print_s_affix(char *str, type_head head)
{
	int		num_size;
	num_size = ft_strlen(str);
	head.width -= num_size;
	head.precision -= num_size;
	if (!head.flag_bar)
	{
		if (head.width > 0 && head.precision > 0)
		{
			if (head.precision >= head.width)
				ft_put_affix(head.precision, '0');
			else
			{
				ft_put_affix(head.width - head.precision, ' ');
				ft_put_affix(head.precision, '0');
			}
		}
		else if (head.precision > 0)
			ft_put_affix(head.precision, '0');
		else if (head.width > 0 && head.flag_zero)
			ft_put_affix(head.width, '0');
		else if (head.width > 0)
			ft_put_affix(head.width, ' ');
		return (0);
	}
	else
	{
		if (head.precision > 0)
			ft_put_affix(head.precision, '0');
		else
			return (head.width);
		return (head.width - head.precision);
	}
}


void		print_s(char* str, type_head head, va_list ap)
{
	char	*ptr;

	ptr = va_arg(ap, char*);
	print_s_affix(ptr, head);
	if (!head.precision)
	{
		head.precision = -1;
	}
	head.width;

	if (head.flag_bar)
	{

	}

	while (*ptr && head.precision--)
		_write(1, ptr++, 1);


}

