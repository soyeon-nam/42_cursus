/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:38 by snam              #+#    #+#             */
/*   Updated: 2021/08/14 20:06:57 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_atoi_ps(const char *str, char ***arr, t_stack *stack)
{
	int				sign;
	unsigned long	ret;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	ret = 0;
	while ('0' <= *str && *str <= '9')
	{
		ret = (ret * 10) + (*str - '0');
		++str;
	}
	if (*str != 0)
		terminate(arr, stack, 1);
	if (ret > (unsigned long)__INT_MAX__ && sign == 1)
		terminate(arr, stack, 1);
	else if (ret > (unsigned long)__INT_MAX__ + 1 && sign == -1)
		terminate(arr, stack, 1);
	return ((int)ret * sign);
}
