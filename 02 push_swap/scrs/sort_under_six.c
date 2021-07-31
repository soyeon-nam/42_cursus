/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:01:23 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:01:24 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	conquer_three(t_node **stack)
{
	int		top;
	int		second;
	int		third;

	top = (*stack)->prev->item;
	second = (*stack)->prev->prev->item;
	third = (*stack)->prev->prev->prev->item;
	if (top < third && third < second)
	{
		do_op("ra", stack, 0);
		do_op("sa", stack, 0);
		do_op("rra", stack, 0);
	}
	else if (second < top && top < third)
		do_op("sa", stack, 0);
	else if (second < third && third < top)
		do_op("rra", stack, 0);
	else if (third < top && top < second)
		do_op("ra", stack, 0);
	else if (third < second && second < top)
	{
		do_op("sa", stack, 0);
		do_op("rra", stack, 0);
	}
}

void			sort_under_six(t_stack *stack, int cnt)
{
	t_node		*stack_a;
	int			pivot;
	int			push;

	push = cnt - 3;
	if (cnt == 2)
		if (stack_a->prev->item > stack_a->item)
			do_op("sa", &stack_a, 0);
	else if (cnt == 3)
		conquer_three(&(stack->a));
	else
	{
		pivot = find_pivot(stack_a, cnt, cnt - 3);
		while (cnt--)
		{
			if (stack_a->item < pivot)
			{
				do_op("pb", &(stack->a), &(stack->b));
				do_op("ra", &(stack->a), &(stack->b));
			}
			else if (stack_a->item == pivot)
				do_op("pb", &(stack->a), &(stack->b));
			else
				do_op("ra", &(stack->a), 0);
		}
		sort_under_six(stack, 3);
		while (push--)
			do_op("pa", &(stack->a), &(stack->b));
	}
}
