/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:33:49 by snam              #+#    #+#             */
/*   Updated: 2021/08/19 04:33:50 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int				state;
	int				prev_state;
	int				token;
	t_format_tag	tag;

	va_start(tag.ap, str);
	reset_tag(&tag);
	tag.total_printed_letter_cnt = 0;
	state = 0;
	while (*str && state != 10)
	{
		prev_state = state;
		token = get_token(*str);
		state = get_state(prev_state, token);
		if (state == -1)
			return (0);
		process(&state, *str, &tag);
		str++;
	}
	va_end(tag.ap);
	return (tag.total_printed_letter_cnt);
}

void	reset_tag(t_format_tag *tag)
{
	tag->flag_bar = 0;
	tag->flag_zero = 0;
	tag->width = 0;
	tag->precision = -1;
}
