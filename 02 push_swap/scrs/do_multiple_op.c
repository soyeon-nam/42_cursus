/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_multiple_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 04:29:59 by snam              #+#    #+#             */
/*   Updated: 2021/08/14 20:06:48 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_multiple_op(t_stack *stack, int num, ...)
{
	va_list			ap;
	char			*op;

	va_start(ap, num);
	while (num--)
	{
		op = va_arg(ap, char *);
		do_op(op, stack);
	}
	va_end(ap);
}
