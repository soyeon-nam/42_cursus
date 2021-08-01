/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:58:27 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 03:58:30 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	conquer_a_three(t_stack *stack)
{
	int		top;
	int		second;
	int		third;

	top = stack->a->next->item;
	second = stack->a->next->next->item;
	third = stack->a->next->next->next->item;
	if (top < third && third < second)
		do_multiple_op(stack, 3, "ra", "sa", "rra");
	else if (second < top && top < third)
		do_op("sa", stack, 0);
	else if (second < third && third < top)
		do_multiple_op(stack, 4, "ra", "sa", "rra", "sa");
	else if (third < top && top < second)
		do_multiple_op(stack, 4, "sa", "ra", "sa", "rra");
	else if (third < second && second < top)
		do_multiple_op(stack, 5, "sa", "ra", "sa", "rra", "sa");
}

static void	conquer_a(t_stack *stack, int cnt)
{
	int		pivot;
	int		push;
	

	if (cnt >= 4)
	{
		pivot = find_pivot(stack->a , cnt, cnt - 3);
		push = cnt - 3;
		while (cnt--)
		{
			if (stack->a->next->item <= pivot)
				do_op("pb", &(stack->a), &(stack->b));
			else
				do_op("ra", &(stack->a), 0);
		}
		conquer_a(stack, 3);
		conquer_b(stack, cnt - 3);
		while (push--)
			do_op("pa", &(stack->a), &(stack->b));
	}
	else if (cnt == 3)
		conquer_a_three(stack);
	else if (cnt == 2)
		if (stack->a->next->item >stack->a->next->next->item)
			do_op("sa", &(stack->a), &(stack->b));
}

void	a_to_b(t_stack *stack, int cnt)
{
	int			rewind;
	int			pivot1;
	int			pivot2;

	if (cnt < 7)
		conquer_a(stack, cnt);
	rewind = cnt;
	pivot1 = find_pivot(stack->a, cnt, cnt - cnt * 2 / 3);
	pivot2 = find_pivot(stack->a, cnt, cnt - cnt / 3);
	while (cnt--)
	{
		if (stack->a->prev->item <= pivot1)
			do_op("pb", &(stack->a), &(stack->b));
		else if (stack->a->prev->item <= pivot2)
			do_multiple_op(stack, 2, "pb", "rb");
		else
			do_op("ra", &(stack->a), &(stack->b));
	}
	cnt = rewind;
	rewind = cnt / 3;
	while (rewind--)
		do_op("rrr", &(stack->a), &(stack->b));
	a_to_b(stack, cnt / 3);
	b_to_a(stack, cnt / 3);
	b_to_a(stack, cnt - (cnt * 2 / 3));
}
