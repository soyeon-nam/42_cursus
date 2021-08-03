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
		do_op("sa", stack);
	else if (second < third && third < top)
		do_multiple_op(stack, 4, "sa", "ra", "sa", "rra");
	else if (third < top && top < second)
		do_multiple_op(stack, 4, "ra", "sa", "rra", "sa");
	else if (third < second && second < top)
		do_multiple_op(stack, 5, "sa", "ra", "sa", "rra", "sa");
}

void	conquer_a(t_stack *stack, int cnt)
{
	int		pivot;
	int		i;

	if (cnt >= 4)
	{
		pivot = find_pivot(stack->a, cnt, cnt - 3);
		i = cnt;
		while (i--)
		{
			if (stack->a->next->item <= pivot)
				do_op("pb", stack);
			else
				do_op("ra", stack);
		}
		i = 3;
		while (i--)
			do_op("rra", stack);
		conquer_a(stack, 3);
		conquer_b(stack, cnt - 3);
	}
	else if (cnt == 3)
		conquer_a_three(stack);
	else if (cnt == 2)
		if (stack->a->next->item > stack->a->next->next->item)
			do_op("sa", stack);
}

void	a_to_b(t_stack *stack, int cnt)
{
	t_sort_info		info;
	int				rewind;			

	if (cnt < 7)
		return (conquer_a(stack, cnt));
	set_pivot(stack->a, &info, cnt);
	while (cnt--)
	{
		if (stack->a->next->item <= info.pivot1)
			do_op("pb", stack);
		else if (stack->a->next->item <= info.pivot2)
			do_multiple_op(stack, 2, "pb", "rb");
		else
			do_op("ra", stack);
	}
	rewind = info.large_cnt;
	if (info.large_cnt < info.middle_cnt)
		do_op("rrb", stack);
	while (rewind--)
		do_op("rrr", stack);
	a_to_b(stack, info.large_cnt);
	b_to_a(stack, info.middle_cnt);
	b_to_a(stack, info.small_cnt);
}
