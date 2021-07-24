/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:22:07 by snam              #+#    #+#             */
/*   Updated: 2021/07/23 21:35:25 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.*/
void		rotate(t_node **stack)
{
	*stack = (*stack)->prev;
}

void		ra(t_node **stack)
{
	rotate(stack);
	write(1, "ra", 2);
}
/*rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.*/
void		rb(t_node **stack)
{
	rotate(stack);
	write(1, "rb", 2);
}

/*rr : ra and rb at the same time.*/
void		rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr", 2);
}
