/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:34:07 by snam              #+#    #+#             */
/*   Updated: 2021/08/19 04:34:08 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_token(char input)
{
	if (input == '%')
		return (0);
	else if (input >= '1' && input <= '9')
		return (1);
	else if (input == '\0')
		return (2);
	else if (input == '.')
		return (3);
	else if (input == '*')
		return (4);
	else if (input == '-')
		return (5);
	else if (input == '0')
		return (6);
	else if (input == 'c' || input == 's' || \
		input == 'd' || input == 'u' || input == 'i' || \
		input == 'x' || input == 'X' || input == 'p')
		return (7);
	else
		return (8);
	return (-1);
}

int	get_state(int prev_state, int token)
{
	static int	arr[81] = {2, 1, 10, 1, 1, 1, 1, 1, 1,
							2, 1, 10, 1, 1, 1, 1, 1, 1,
							8, 3, -1, 5, 4, 2, 2, 8, -1,
							8, 3, -1, 5, -1, -1, 3, 8, -1,
							8, -1, -1, 5, -1, -1, -1, 8, -1,
							8, 6, -1, -1, 7, -1, 6, 8, -1,
							8, 6, -1, -1, -1, -1, 6, 8, -1,
							8, -1, -1, -1, -1, -1, -1, 8, -1};

	return (arr[(prev_state * 9) + token]);
}

void	process(int *state, char input, t_format_tag *tag)
{
	if (*state == 1)
		ft_putchar(input, tag);
	else if (*state == 2)
		process_2(input, tag);
	else if (*state == 3)
		update_width(input, tag);
	else if (*state == 4)
		process_4(tag);
	else if (*state == 5)
		tag->precision = 0;
	else if (*state == 6)
		update_precision(input, tag);
	else if (*state == 7)
		process_7(tag);
	else if (*state == 8)
	{
		*state = 0;
		process_8(input, tag);
	}
}
