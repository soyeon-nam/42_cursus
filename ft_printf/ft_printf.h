/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:33:28 by snam              #+#    #+#             */
/*   Updated: 2021/06/13 11:05:40 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct		s_format_tag
{
	int				flag_bar;
	int				flag_zero;
	int				width;
	int				precision;
	int				check_minus_width;
}					t_ft;

int					ft_printf(const char *str, ...);
void				process_state(int *state, char spec, va_list ap);
int					create_string(char spec, va_list ap);

void				process_bar(int state);
void				process_zero(int state, char input);
void				process_asterisk(int state, va_list ap);
void				process_one_to_nine(int state, char input);
void				process_dot(int state);

int					get_token(int prev_state, char input, va_list ap);
int					get_token_format_tag(int prev_state,
									char input, va_list ap);
int					get_state(int state, int input);

int					create_c(va_list ap);
int					create_percent(void);
int					create_p(va_list ap);

int					create_di(va_list ap);
void				set_print_numbers_di(int *size_width,
								int *size_precision, int size_num, int num);
void				set_print_numbers_negative(int *size_width,
									int *size_precision, int size_num);
void				set_print_numbers_positive(int *size_width,
									int *size_precision, int size_num);
void				create_di_prefix(int size_precision,
							int *size_width, int minus_flag);

int					create_s(va_list ap);
void				set_print_numbers_s(int *size_width,
							int *size_precision, int size_num);
void				print_arg_string(char *str, int size_precision);

int					create_u(va_list ap);
void				set_print_numbers_u(int *size_width,
							int *size_precision, int size_num, size_t num);

int					create_x(char mode, va_list ap);
void				set_print_numbers_x(int *size_width,
						int *size_precision, int size_num, unsigned int num);

void				create__x_prefix(int size_precision,
						int *size_width, int minus_flag);
void				print_x(char mode, unsigned int nb, int base_num);

int					count_digit(int num);
int					count_digit_u(unsigned int num);
int					count_digit_hex(long long num);
int					count_digit_x(unsigned int num);

void				print_base_upper(long nb, int base_num);
void				print_base_lower(long nb, int base_num);
void				print_base_upper_x(unsigned int nb, int base_num);
void				print_base_lower_x(unsigned int nb, int base_num);

size_t				ft_strlen(const char *s);
void				ft_putnbr(long long nb);
void				ft_putchar(char c);

void				ft_put_affix(int *num, char c);
void				ft_put_affix_p(long long *num, char c);
void				update_width(char c);
void				update_precision(char c);
void				reset_tag(void);

#endif
