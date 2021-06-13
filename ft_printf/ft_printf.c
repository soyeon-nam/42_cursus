/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:33:24 by snam              #+#    #+#             */
/*   Updated: 2021/06/13 11:05:29 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ft		g_tag = {0, 0, 0, -1, 0};
int			g_ret_print = 0;

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
		process_state(&state, *str, ap);
		if (state == 10)
			break ;
		if (state == -1)
		{
			write(1, "\n>>>> ERROR : CANNOT PRINT\n", 27);
			return (-1);
		}
		str++;
	}
	va_end(ap);
	return (g_ret_print);
}

void		process_state(int *state, char spec, va_list ap)
{
	if (*state == 1)
		ft_putchar(spec);
	if (*state == 8)
	{
		if ((create_string(spec, ap) == -1))
			*state = -1;
		else
			*state = 0;
	}
}

int			create_string(char spec, va_list ap)
{
	int				ret;

	ret = -1;
	if (spec == 'c')
		ret = create_c(ap);
	else if (spec == 's')
		ret = create_s(ap);
	else if (spec == 'p')
		ret = create_p(ap);
	else if (spec == '%')
		ret = create_percent();
	else if (spec == 'd' || spec == 'i')
		ret = create_di(ap);
	else if (spec == 'u')
		ret = create_u(ap);
	else if (spec == 'x')
		ret = create_x('x', ap);
	else if (spec == 'X')
		ret = create_x('X', ap);
	reset_tag();
	return (ret);
}
