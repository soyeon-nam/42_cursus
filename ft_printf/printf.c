#include "printf.h"

int		ft_printf(const char* str, ...)
{
	int			ret;
	va_list		ap;

	va_start(ap, str);

	while (*str)
	{
		while (*str != '%' && *str )
		{
			_write(1, str, 1);
			++str;
		}
		if (*str == '%')
		{
			++str;
			(char *)str += print_fs(str, ap);
		}
	}
	return (0);
}

// s puxX%

int		print_fs(char *str, va_list ap)
{
	type_head	head;
	char*		temp;

	temp = str;
	head = put_head_fs(&str);
	if (*str == 'c')
		print_c(str, head, ap);
	else if (*str == 'd' || *str == 'i')
		print_d_i(*str, head, ap);

	else if (*str == 's')
		print_s(*str, head, ap);
	else if (*str == 'p')
		print_s(*str, head, ap);
	else if (*str == 'u')
		print_s(*str, head, ap);
	else if (*str == 'x')
		print_s(*str, head, ap);
	else if (*str == 'X')
		print_s(*str, head, ap);
	else if (*str == '%')
		_write(1, "%", 1);


	/*
	...
	*/

	else 
		return (str - temp);



	return (str - temp + 1);
}

// - 0 .*
type_head		put_head_fs(char **str)
{
	type_head	head;

	head.flag_bar = 0;
	head.flag_zero = 0;
	head.width = 0;
	head.precision = 0;
	while (**str == '-' || **str == '0')
	{
		if (**str == '-')
			head.flag_bar = 1;
		if (**str == '0')
			head.flag_zero = 1;
		++*str;
	}
	if ('0' <= **str && **str <= '9')
	{
		head.width = ft_atoi(*str);
		*str += count_digit(head.width);
	}
	if (**str == '.')
	{
		++*str;
		head.precision = ft_atoi(*str);
		*str += count_digit(head.precision);

	}
	return (head);
}



//diuxX% ¡¯- 0 .* 

