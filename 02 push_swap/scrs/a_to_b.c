/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:58:27 by snam              #+#    #+#             */
/*   Updated: 2021/08/05 03:03:39 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_acsend(t_node *stack, int cnt)
{
	while (cnt--)
	{
		if (stack->next->item > stack->next->next->item)
			return (0);
		stack = stack->next;
	}
	return (1);
}

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

static void	conquer_a_four(t_stack *stack)
{
	t_node		**a;
	t_node		**b;

	a = &(stack->a->next);
	b = &(stack->b->next);
	if ((*a)->item > (*a)->next->item)
		do_op("sa", stack);
	do_op("pb", stack);
	if ((*a)->item > (*a)->next->item)
		do_op("sa", stack);
	do_op("pb", stack);
	if ((*a)->item > (*a)->next->item && (*b)->item < (*b)->next->item)
		do_op("ss", stack);
	else if ((*a)->item > (*a)->next->item)
		do_op("sa", stack);
	else if ((*b)->item < (*b)->next->item)
		do_op("sb", stack);
	do_op("pa", stack);
	if ((*a)->item > (*a)->next->item)
		do_op("sa", stack);
	do_op("pa", stack);
	if ((*a)->item > (*a)->next->item)
		do_op("sa", stack);
}

void	conquer_a(t_stack *stack, int cnt)
{
	int		pivot;
	int		i;

	if (cnt > 4)
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
		rewind_stack(stack, 3, 0);
		conquer_a(stack, 3);
		conquer_b(stack, cnt - 3);
	}
	else if (cnt == 4)
		conquer_a_four(stack);
	else if (cnt == 3)
		conquer_a_three(stack);
	else if (cnt == 2)
		if (stack->a->next->item > stack->a->next->next->item)
			do_op("sa", stack);
}

void	a_to_b(t_stack *stack, int cnt)
{
	t_sort_info		info;

	if (is_acsend(stack->a, cnt))
		return ;
	if (cnt < 7)
		return (conquer_a(stack, cnt));
	divide_a(stack, cnt, &info);
	a_to_b(stack, info.large_cnt);
	b_to_a(stack, info.middle_cnt);
	b_to_a(stack, info.small_cnt);
}
