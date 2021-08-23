/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:29:38 by snam              #+#    #+#             */
/*   Updated: 2021/08/12 00:29:40 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	conquer_a_three(t_stack *stack)
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
		do_multiple_op(stack, 4, "sa", "ra", "sa", "rra");
	else if (third < top && top < second)
		do_multiple_op(stack, 4, "ra", "sa", "rra", "sa");
	else if (third < second && second < top)
		do_multiple_op(stack, 5, "sa", "ra", "sa", "rra", "sa");
}

static void	conquer_a_four(t_stack *stack)
{
	if (A_top->item > A_top->next->item)
		do_op("sa", stack);
	do_op("pb", stack);
	if (A_top->item > A_top->next->item)
		do_op("sa", stack);
	do_op("pb", stack);
	if (A_top->item > A_top->next->item && B_top->item < B_top->next->item)
		do_op("ss", stack);
	else if (A_top->item > A_top->next->item)
		do_op("sa", stack);
	else if (B_top->item < B_top->next->item)
		do_op("sb", stack);
	do_op("pa", stack);
	if (A_top->item > A_top->next->item)
		do_op("sa", stack);
	do_op("pa", stack);
	if (A_top->item > A_top->next->item)
		do_op("sa", stack);
}

void	conquer_a(t_stack *stack, int cnt)
{
	if (cnt == 4)
		conquer_a_four(stack);
	else if (cnt == 3)
		conquer_a_three(stack);
	else if (cnt == 2)
		if (A_top->item > A_top->next->item)
			do_op("sa", stack);
}
