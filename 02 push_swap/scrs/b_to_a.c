/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:18 by snam              #+#    #+#             */
/*   Updated: 2021/08/05 03:03:56 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_decsend(t_node *stack, int cnt)
{
	while (cnt--)
	{
		if (stack->next->item > stack->next->next->item)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	conquer_b_three(t_stack *stack)
{
	int		top;
	int		second;
	int		third;

	top = stack->a->next->item;
	second = stack->a->next->next->item;
	third = stack->a->next->next->next->item;
	if (top < second && second < third)
		do_multiple_op(stack, 6, "pa", "ra", "pa", "pa", "sa", "rra");
	else if (top < third && third < second)
		do_multiple_op(stack, 5, "sb", "pa", "sb", "pa", "pa");
	else if (second < top && top < third)
		do_multiple_op(stack, 5, "pa", "sb", "pa", "sb", "pa");
	else if (second < third && third < top)
		do_multiple_op(stack, 4, "pa", "sb", "pa", "pa");
	else if (third < top && top < second)
		do_multiple_op(stack, 4, "sb", "pa", "pa", "pa");
	else if (third < second && second < top)
		do_multiple_op(stack, 3, "pa", "pa", "pa");
}

void	conquer_b(t_stack *stack, int cnt)
{
	int		pivot;
	int		i;

	if (cnt >= 4)
	{
		pivot = find_pivot(stack->b, cnt, cnt - 3);
		i = cnt;
		while (i--)
		{
			if (stack->b->next->item > pivot)
				do_op("pa", stack);
			else
				do_op("rb", stack);
		}
		conquer_a(stack, 3);
		i = cnt - 3;
		while (i--)
			do_op("rrb", stack);
		conquer_b(stack, cnt - 3);
		return ;
	}
	i = cnt;
	while (i--)
		do_op("pa", stack);
	conquer_a(stack, cnt);
}

void	b_to_a(t_stack *stack, int cnt)
{
	t_sort_info		info;
	t_rewind		rewind;

	if (cnt < 7)
	{	
		if (!is_decsend(stack->b, cnt))
			return (conquer_b(stack, cnt));
		while (cnt--)
			do_op("pa", stack);
		return ;
	}
	divide_b(stack, cnt, &info, &rewind);
	a_to_b(stack, info.large_cnt);
	rewind_stack(stack, rewind.rra, rewind.rrb);
	a_to_b(stack, info.middle_cnt);
	b_to_a(stack, info.small_cnt);
}
