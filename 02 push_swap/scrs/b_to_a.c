/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:18 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:00:19 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	conquer_b_three(t_stack *stack)
{
	int		top;
	int		second;
	int		third;

	top = stack->a->next->item;
	second = stack->a->next->next->item;
	third = stack->a->next->next->next->item;
	if (top < second && second < third)
		do_multiple_op(stack, 5, "sb", "rb", "sb", "rrb", "sb");
	else if (top < third && third < second)
		do_multiple_op(stack, 4, "sb", "rb", "sb", "rrb");
	else if (second < top && top < third)
		do_multiple_op(stack, 4, "rb", "sb", "rrb", "sb");
	else if (second < third && third < top)
		do_op("sb", stack, 0);
	else if (third < top && top < second)
		do_multiple_op(stack, 3, "rb", "sb", "rrb");
}

static void	conquer_b(t_stack *stack, int cnt)
{
	int		pivot;
	int		i;

	if (cnt >= 4)
	{
		pivot = find_pivot(stack->a , cnt, cnt - 3);
		i = cnt;
		while (i--)
		{
			if (stack->a->next->item > pivot)
				do_op("pb", &(stack->a), &(stack->b));
			else
				do_op("ra", &(stack->a), 0);
		}
		conquer_a(stack, 3);
		conquer_b(stack, cnt - 3);
		cnt -= 3;
	}
	else if (cnt == 3)
		conquer_b_three(stack);
	else if (cnt == 2)
		if (stack->a->next->item >stack->a->next->next->item)
			do_op("sb", &(stack->a), &(stack->b));
	while (cnt--)
		do_op("pa", &(stack->a), &(stack->b));
}

void	b_to_a(t_stack *stack, int cnt)
{
	int			rewind;
	int			pivot1;
	int			pivot2;

	if (cnt < 7)
		conquer_b(stack, cnt);
	rewind = cnt;
	pivot1 = find_pivot(stack->a, cnt, cnt / 3);
	pivot2 = find_pivot(stack->a, cnt, cnt * 2 / 3);
	while (cnt--)
	{
		if (stack->a->next->item < pivot1)
			do_op("ra", &(stack->a), &(stack->b));
		else if (stack->a->next->item < pivot2)
			do_multiple_op(stack, 2, "pa", "ra");
		else
			do_op("pa", &(stack->a), &(stack->b));
	}
	a_to_b(stack, cnt / 3);
	cnt = rewind;
	rewind = cnt - (cnt * 2 / 3);
	while (rewind--)
		do_op("rrr", &(stack->a), &(stack->b));
	a_to_b(stack, cnt / 3);
	b_to_a(stack, cnt - (cnt * 2 / 3));
}
