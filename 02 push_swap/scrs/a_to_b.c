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

static void		conquer_a_231(t_node **stack)
{
	do_op("ra", stack, 0);
	do_op("sa", stack, 0);
	do_op("rra", stack, 0);
	do_op("sa", stack, 0);
}

static void		conquer_a_312(t_node **stack)
{
	do_op("sa", stack, 0);
	do_op("ra", stack, 0);
	do_op("sa", stack, 0);
	do_op("rra", stack, 0);
}

static void		conquer_a_321(t_node **stack)
{
	do_op("sa", stack, 0);
	do_op("ra", stack, 0);
	do_op("sa", stack, 0);
	do_op("rra", stack, 0);
	do_op("sa", stack, 0);
}

static void		conquer_a(t_node **stack, int cnt)
{
	t_node		*top;
	t_node		*second;
	t_node		*third;

	if (cnt <= 3)
	{
		top = (*stack)->prev->item;
		second = top->prev->item;
		third = second->prev->item;
		if (top < third && third < second)
		{
			do_op("ra", stack, 0);
			do_op("sa", stack, 0);
			do_op("rra", stack, 0);
		}
		else if (second < top && top < third)
			do_op("sa", stack, 0);
		else if (second < third && third < top)
			conquer_a_231(stack);
		else if (third < top && top < second)
			conquer_a_312(stack);
		else if (third < second && second < top)
			conquer_a_321(stack);
	}
	// else if (cnt == 2)
	// else
	// conquer_a(stack, cnmt);
}

void			a_to_b(t_stack *stack, int cnt)
{
	int			rewind;
	int			pivot1;
	int			pivot2;

	if (cnt < 7)  //최적화하는 것은 7이하 일 때도 고민해보기
		conquer_a(&(stack->a), cnt);
	rewind = cnt;
	pivot1 = find_pivot(stack->a, cnt, cnt - cnt * 2 / 3);
	pivot2 = find_pivot(stack->a, cnt, cnt - cnt / 3);
	while (cnt--)
	{
		if (stack->a->prev->item <= pivot1)
			do_op("pb", &(stack->a), &(stack->b));
		else if (stack->a->prev->item <= pivot2)
		{
			do_op("pb", &(stack->a), &(stack->b));
			do_op("rb", &(stack->a), &(stack->b));
		}
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
