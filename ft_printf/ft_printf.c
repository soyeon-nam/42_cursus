/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:33:24 by snam              #+#    #+#             */
/*   Updated: 2021/06/10 15:29:50 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

type_ft		g_tag = {0, 0, 0, -1, 0};
int			ret_print = 0;

void	set_print_numbers_u(size_t *size_width, size_t *size_precision, size_t size_num, int num)
{
	*size_width = g_tag.width;
	*size_precision = g_tag.precision;
	if (num < 0)
	{
		if ((size_t)g_tag.precision <= size_num)
		{
			*size_width -= (size_num + 1);
			*size_precision = 0;
		}
		else
		{
			*size_width -= (g_tag.precision + 1);
			*size_precision -= size_num;
		}
	}
	else
	{
		if ((size_t)g_tag.precision > size_num)
		{
			*size_width -= g_tag.precision;
			*size_precision -= size_num;
		}
		else
		{
			*size_width -= size_num;
			*size_precision = 0;
		}
	}
}

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
