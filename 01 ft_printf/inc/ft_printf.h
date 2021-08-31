/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 01:49:29 by snam              #+#    #+#             */
/*   Updated: 2021/08/19 01:49:31 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

#include <stdio.h>



typedef struct s_format_tag
{
	int				flag_bar;
	int				flag_zero;
	int				width;
	int				precision;
	int				total_printed_letter_cnt;
	va_list			ap;
}					t_format_tag;

typedef struct s_print_info
{
	int				width_len;
	int				precision_len;
	int				arg_len;
	int				minus;
}					t_print_info;

/*
** ========== ft_printf.c ==========
*/
int			ft_printf(const char *str, ...);
void		reset_tag(t_format_tag *tag);

/*
** ========== state_machine.c ==========
*/
int			get_token(char input);
int			get_state(int prev_state, int token);
void		process(int *state, char input, t_format_tag *tag);

/*
** ========== process.c ==========
*/
void		process_2(char input, t_format_tag *tag);
void		process_4(t_format_tag *tag);
void		process_7(t_format_tag *tag);
void		process_8(char spec, t_format_tag *tag);

/*
** ========== create_cppc.c ==========
*/
void		create_c(t_format_tag *tag);
void		create_percent(t_format_tag *tag);
void		create_p(t_format_tag *tag);

/*
** ========== create_diux.c ==========
*/
void		create_di(t_format_tag *tag);
void		create_u(t_format_tag *tag);
void		create_x(char mode, t_format_tag *tag);
/*
** ========== create_s.c ==========
*/
void		create_s(t_format_tag *tag);

/*
** ========== set_print_info.c ==========
*/
void		set_print_info(t_print_info *info, int size_num, t_format_tag *tag);

/*
** ========== count_digit.c ==========
*/
int			count_digit(int num);
int			count_digit_u(unsigned int num);
int			count_digit_hex(size_t num);
size_t		ft_strlen(const char *s);

/*
** ========== count_digit.c ==========
*/
void		ft_putchar(char c, t_format_tag *tag);
void		ft_multiple_putchar(int num, char c, t_format_tag *tag);
void		ft_putnbr(long long nb, t_format_tag *tag);
void		print_base_upper(long nb, t_format_tag *tag);
void		print_base_lower(long nb, t_format_tag *tag);

/*
** ========== update_nbr.c ==========
*/
void		update_width(char c, t_format_tag *tag);
void		update_precision(char c, t_format_tag *tag);

#endif
