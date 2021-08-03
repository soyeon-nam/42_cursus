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

// static void	conquer_b_three(t_stack *stack)
// {
// 	int		top;
// 	int		second;
// 	int		third;

// 	top = stack->b->next->item;
// 	second = stack->b->next->next->item;
// 	third = stack->b->next->next->next->item;
// 	if (top < second && second < third)
// 		do_multiple_op(stack, 5, "sb", "rb", "sb", "rrb", "sb");
// 	else if (top < third && third < second)
// 		do_multiple_op(stack, 4, "sb", "rb", "sb", "rrb");
// 	else if (second < top && top < third)
// 		do_multiple_op(stack, 4, "rb", "sb", "rrb", "sb");
// 	else if (second < third && third < top)
// 		do_multiple_op(stack, 3, "rb", "sb", "rrb");
// 	else if (third < top && top < second)
// 		do_op("sb", &(stack->a), &(stack->b));
// }

void	conquer_b(t_stack *stack, int cnt)
{
	int		pivot;
	int		i;

	if (cnt >= 4)
	{
		pivot = find_pivot(stack->b , cnt, cnt - 3);
		i = cnt;
		while (i--)
		{
			if (stack->b->next->item > pivot)
				do_op("pa", &(stack->a), &(stack->b));
			else
				do_op("rb", &(stack->a), &(stack->b));
		}
		conquer_a(stack, 3);
		i = cnt - 3;
		while (i--)
			do_op("rrb", &(stack->a), &(stack->b));
		conquer_b(stack, cnt - 3);
	}
	else
	{
		i = cnt;
		while (i--)
			do_op("pa", &(stack->a), &(stack->b));
		conquer_a(stack, cnt);		
	}
}

void	b_to_a(t_stack *stack, int cnt)
{
	t_sort_info		info;
	int				rewind;			

	if (cnt < 7)
		return (conquer_b(stack, cnt));
	set_pivot(stack->b, &info, cnt);
	while (cnt--)
	{
		if (stack->b->next->item <= info.pivot1)
				do_op("rb", &(stack->a), &(stack->b));

		else if (stack->b->next->item <= info.pivot2)
			do_multiple_op(stack, 2, "pa", "ra");
		else
			do_op("pa", &(stack->a), &(stack->b));
	}
	a_to_b(stack, info.large_cnt);
	rewind = info.middle_cnt;
	if (info.middle_cnt < info.small_cnt)
		do_op("rrb", &(stack->a), &(stack->b));
	while (rewind--)
		do_op("rrr", &(stack->a), &(stack->b));
	a_to_b(stack, info.middle_cnt);
	b_to_a(stack, info.small_cnt);
}
