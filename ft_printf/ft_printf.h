/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:33:28 by snam              #+#    #+#             */
/*   Updated: 2021/06/10 14:44:23 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		format_tag 
{
	int		flag_bar;
	int		flag_zero;
	int		width;
	int		precision;
	int		check_minus_width;
}					type_ft; 

int			ft_printf(const char *str, ...);
int			get_token(int prev_state, char input, va_list ap);
int			get_token_format_tag(int prev_state, char input, va_list ap);
int			get_state(int state, int input);

void		process_bar(int state);
void		process_zero(int state, char input);
void		process_asterisk(int state, va_list ap);
void		process_one_to_nine(int state, char input);
void		process_dot(int state);

void		update_num(char c, int mode);
void		reset_tag();
void		ft_put_affix(long long *num, char c);
size_t		ft_strlen(const char* s);
int			count_digit(int num);
void		ft_putnbr(long long nb);
void		print_base_lower(long nb, int base_num);
void		print_base_upper(long nb, int base_num);

int			create_string(char spec, va_list ap);
int			create_c(va_list ap);
int			create_s(va_list ap);
int			create_p(va_list ap);
int			create_percent();
void	set_print_numbers_di(long long *size_width, long long *size_precision, long long size_num, int num);
void		set_print_numbers_s(long long *size_width, long long *size_precision, long long size_num);
int			count_digit_hex(long long num);

int			create_di(va_list ap);
int			create_u(va_list ap);
int			create_x(va_list ap);
int			create_X(va_list ap);

#endif
