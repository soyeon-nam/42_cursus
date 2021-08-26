/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:09:08 by snam              #+#    #+#             */
/*   Updated: 2021/08/22 21:09:09 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"

# include <stdio.h>

# ifndef PID_MAX
#  define PID_MAX 99998
# endif

struct s_bit_field
{
	bool	first	: 1;
	bool	second	: 1;
	bool	third	: 1;
	bool	fourth	: 1;
	bool	fifth	: 1;
	bool	sixth	: 1;
	bool	seventh	: 1;
	bool	end		: 1;
};

union	u_bit_field
{
	struct s_bit_field		bf;
	unsigned char			uc;
} ;

typedef struct s_info
{
	int						bit_ordinal_nb;
	union u_bit_field		bit_field;
}	t_info;

typedef struct s_info_b
{
	int						oponent_pid;
	int						bit_size;
	int						bit_ordinal_nb;
	union u_bit_field		*bit_field[4];
}	t_info_b;

#endif
