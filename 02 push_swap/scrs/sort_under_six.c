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

static void	conquer_three(t_stack *stack)
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
		do_op("sa", &(stack->a), &(stack->b));
	else if (second < third && third < top)
		do_op("ra", &(stack->a), &(stack->b));
	else if (third < top && top < second)
		do_op("rra", &(stack->a), &(stack->b));
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
		if (stack->a->next->item < pivot)
			do_multiple_op(stack, 2, "pb", "rb");
		else if (stack->a->next->item == pivot)
			do_op("pb", &(stack->a), &(stack->b));
		else
			do_op("ra", &(stack->a), &(stack->b));
	}
	conquer_three(stack);
	while (push--)
		do_op("pa", &(stack->a), &(stack->b));
}

void			sort_under_six(t_stack *stack, int cnt)
{
	if (cnt == 2)
	{
		if (stack->a->next->item > stack->a->item)
			do_op("sa", &(stack->a), &(stack->b));
	}
	else if (cnt == 3)
		conquer_three(stack);
	else
		conquer_four_five(stack, cnt);
}


//52314