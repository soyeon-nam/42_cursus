/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:33:24 by snam              #+#    #+#             */
/*   Updated: 2021/06/10 23:02:54 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

type_ft		g_tag = {0, 0, 0, -1, 0};
int			ret_print = 0;



int			ft_printf(const char *str, ...)
{
	int				state;
	int				prev_state; //
	int				token;
	va_list			ap;
	char			*ptr;

	va_start(ap, str);
	ptr = (char *)str;
	state = 0;
	ret_print = 0;
	while (*str)
	{
		prev_state = state;//
		token = get_token(prev_state, *str, ap);
		state = get_state(state, token);
		//printf("\n\n[%c, %d] %d -> %d\n\n", *str, token, prev_state, state);//
		if (state == 1)
		{
			ret_print++;
			write(1, str, 1);
		}
		if (state == 8)
		{
			if ((create_string(*str, ap) == -1))
				state = -1;
			else
				state = 0;
		}
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
	return (ret_print);
}
