/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:33:24 by snam              #+#    #+#             */
/*   Updated: 2021/06/14 19:11:19 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ft		g_tag = {0, 0, 0, -1, 0};
int			g_ret_print;

int			ft_printf(const char *str, ...)
{
	int				state;
	int				prev_state;
	int				token;
	va_list			ap;

	va_start(ap, str);
	state = 0;
	g_ret_print = 0;
	while (*str)
	{
		prev_state = state;
		token = get_token(prev_state, *str, ap);
		state = get_state(state, token);
		switch (state){
		case 1:
			ft_putchar(*str);
			break;
		case 8:
			create_string(*str, ap);
			state = 0;
			break;
		case 10:
			break;
		case -1:
			write(1, "\n>>>> ERROR : CANNOT PRINT\n", 27);
			return (-1);
		default:
			break;
		}
		str++;
	}
	va_end(ap);
	return (g_ret_print);
}

void			create_string(char spec, va_list ap)
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
