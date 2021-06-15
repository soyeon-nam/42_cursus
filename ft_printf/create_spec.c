#include "ft_printf.h"

void			create_spec(char spec, va_list ap)
{
	switch (spec){
	case 'c':
		create_c(ap);
		break ;
	case 's':
		create_s(ap);
		break ;
	case 'p':
		create_p(ap);
		break ;
	case '%':
		create_percent();
		break ;
	case 'd':
		create_di(ap);
		break ;
	case 'i':
		create_di(ap);
		break ;
	case 'u':
		create_u(ap);
		break ;
	case 'x':
		create_x('x', ap);
		break ;
	case 'X':
		create_x('X', ap);
		break ;
	default:
		break ;
	}
	reset_tag();
}
