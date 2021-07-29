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

static void		conquer_a_123(t_node **stack)
{
	do_op("sb", stack, 0);
	do_op("rb", stack, 0);
	do_op("sb", stack, 0);
	do_op("rrb", stack, 0);
	do_op("sb", stack, 0);
}

static void		conquer_a_132(t_node **stack)
{
	do_op("sb", stack, 0);
	do_op("rb", stack, 0);
	do_op("sb", stack, 0);
	do_op("rrb", stack, 0);
}

static void		conquer_b_213(t_node **stack)
{
	do_op("rb", stack, 0);
	do_op("sb", stack, 0);
	do_op("rrb", stack, 0);
	do_op("sb", stack, 0);
}

static void		conquer_b(t_node **stack)
{
	t_node		*top;
	t_node		*second;
	t_node		*third;

	top = (*stack)->prev->item;
	second = top->prev->item;
	third = second->prev->item;
	if (top < second && second < third)
		conquer_b_123(stack);
	else if (top < third && third < second)
		conquer_b_132(stack);
	else if (second < top && top < third)
		conquer_b_213(stack);
	else if (second < third && third < top)
		do_op("sb", stack, 0);
	else if (third < top && top < second)
	{
		do_op("rb", stack, 0);
		do_op("sb", stack, 0);
		do_op("rrb", stack, 0);	
	}
}

void            b_to_a(t_stack *stack, int cnt)
{
	int			rewind;
	int			pivot1;
	int			pivot2;

	if (cnt < 3)  //최적화하는 것은 7이하 일 때도 고민해보기
		conquer_b(&(stack->b));
	rewind = cnt;
	pivot1 = find_pivot(stack->a, cnt, cnt/3);
	pivot2 = find_pivot(stack->a, cnt, cnt * 2 / 3);
	while (cnt--)
	{
		if (stack->a->prev->item < pivot1)
			do_op("ra", &(stack->a), &(stack->b));
		else if (stack->a->prev->item < pivot2)
		{
			do_op("pa", &(stack->a), &(stack->b));
			do_op("ra", &(stack->a), &(stack->b));
		}
		else
			do_op("pa", &(stack->a), &(stack->b));
	}
	cnt = rewind;
	rewind = cnt - (cnt * 2 / 3);
	while (rewind--)
		do_op("rrr", &(stack->a), &(stack->b));
	b_to_a(stack, cnt);
	b_to_a(stack, cnt);
	a_to_b(stack, cnt);
}