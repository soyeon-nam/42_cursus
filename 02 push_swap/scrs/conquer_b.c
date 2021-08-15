/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:29:46 by snam              #+#    #+#             */
/*   Updated: 2021/08/14 20:06:45 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	conquer_b_three(t_stack *stack)
{
	int		top;
	int		second;
	int		third;

	top = stack->b->next->item;
	second = stack->b->next->next->item;
	third = stack->b->next->next->next->item;
	if (top < second && second < third)
		do_multiple_op(stack, 6, "pa", "ra", "pa", "pa", "sa", "rra");
	else if (top < third && third < second)
		do_multiple_op(stack, 5, "sb", "pa", "sb", "pa", "pa");
	else if (second < top && top < third)
		do_multiple_op(stack, 5, "pa", "sb", "pa", "sa", "pa");
	else if (second < third && third < top)
		do_multiple_op(stack, 4, "pa", "sb", "pa", "pa");
	else if (third < top && top < second)
		do_multiple_op(stack, 4, "sb", "pa", "pa", "pa");
	else if (third < second && second < top)
		do_multiple_op(stack, 3, "pa", "pa", "pa");
}

static void	conquer_b_four(t_stack *stack)
{
	int		pivot;
	int		rewind;
	int		i;

	pivot = find_pivot(stack->b, 4, 2);
	i = 0;
	rewind = 0;
	while (i++ < 4)
	{
		if (pivot >= stack->b->next->item && ++rewind)
			do_op("rb", stack);
		else
			do_op("pa", stack);
		if (i - rewind >= 2)
			break ;
	}
	do_multiple_op(stack, rewind, "rrb", "rrb");
	if ((stack->a->next->item > stack->a->next->next->item) \
		&& (stack->b->next->item < stack->b->next->next->item))
		do_op("ss", stack);
	else if (stack->a->next->item > stack->a->next->next->item)
		do_op("sa", stack);
	else if (stack->b->next->item < stack->b->next->next->item)
		do_op("sb", stack);
	do_multiple_op(stack, 2, "pa", "pa");
}

void	conquer_b(t_stack *stack, int cnt)
{
	if (cnt == 4)
		conquer_b_four(stack);
	else if (cnt == 3)
		conquer_b_three(stack);
	else if (cnt == 2)
	{
		if (stack->b->next->item < stack->b->next->next->item)
			do_op("sb", stack);
		do_multiple_op(stack, 2, "pa", "pa");
	}
	else
		do_op("pa", stack);
}
