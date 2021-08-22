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

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>

typedef struct s_info
{
	int		bit_index;
	int		*bit_arr;
} t_info;

#endif
