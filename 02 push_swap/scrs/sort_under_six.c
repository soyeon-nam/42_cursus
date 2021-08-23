/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:01:23 by snam              #+#    #+#             */
/*   Updated: 2021/08/14 20:07:14 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	conquer_three(t_stack *stack)
{
	int		top;
	int		second;
	int		third;

	top = A_top->item;
	second = A_top->next->item;
	third = A_top->next->next->item;
	if (top < third && third < second)
		do_multiple_op(stack, 3, "ra", "sa", "rra");
	else if (second < top && top < third)
		do_op("sa", stack);
	else if (second < third && third < top)
		do_op("ra", stack);
	else if (third < top && top < second)
		do_op("rra", stack);
	else if (third < second && second < top)
		do_multiple_op(stack, 2, "sa", "rra");
}

static void	conquer_four_five(t_stack *stack, int cnt)
{
	int			pivot;
	int			push;

	push = cnt - 3;
	pivot = find_pivot(stack->a, cnt, cnt - 3);
	while (cnt--)
	{
		if (A_top->item < pivot)
			do_multiple_op(stack, 2, "pb", "rb");
		else if (A_top->item == pivot)
			do_op("pb", stack);
		else
			do_op("ra", stack);
	}
	conquer_three(stack);
	while (push--)
		do_op("pa", stack);
}

void	sort_under_six(t_stack *stack, int cnt)
{
	if (is_ascend(stack->a, cnt))
		return ;
	if (cnt == 2)
	{
		if (A_top->item > stack->a->item)
			do_op("sa", stack);
	}
	else if (cnt == 3)
		conquer_three(stack);
	else
		conquer_four_five(stack, cnt);
}
