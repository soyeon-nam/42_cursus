/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:03:00 by snam              #+#    #+#             */
/*   Updated: 2021/06/10 23:03:01 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ft_printf.h"

extern type_ft		g_tag;
extern int			ret_print;


int			get_token(int prev_state, char input, va_list ap)
{
	if (input == '%')
		return (0);
	else if (input >= '1' && input <= '9')
	{
		process_one_to_nine(prev_state, input);
		return (1);
	}
	else if (input == '\0')
		return (2);
	else if (input == '.' || input == '*' || input == '-' || input == '0')
		return (get_token_format_tag(prev_state, input, ap));
	else if (input == 'c' || input == 's' ||
			input == 'd' || input == 'u' || input == 'i' ||
			input == 'x' || input == 'X' || input == 'p')
		return (7);
	else
		return (8);
	return (-1);
}

int			get_token_format_tag(int prev_state, char input, va_list ap)
{
	if (input == '.')
	{
		process_dot(prev_state);
		return (3);
	}
	else if (input == '*')
	{
		process_asterisk(prev_state, ap);
		return (4);
	}
	else if (input == '-')
	{
		process_bar(prev_state);
		return (5);
	}
	else if (input == '0')
	{
		process_zero(prev_state, input);
		return (6);
	}
	return (-1);
}

int			get_state(int state, int input)
{
	static int arr[81] = {2, 1, 10, 1, 1, 1, 1, 1, 1,
						2, 1, 10, 1, 1, 1, 1, 1, 1,
						8, 3, -1, 5, 4, 2, 2, 8, -1,
						8, 3, -1, 5, -1, -1, 3, 8, -1,
						8, -1, -1, 5, -1, -1, -1, 8, -1,
						8, 6, -1, -1, 7, -1, 6, 8, -1,
						8, 6, -1, -1, -1, -1, 6, 8, -1,
						8, -1, -1, -1, -1, -1, -1, 8, -1};

	return (arr[(state * 9) + input]);
}
