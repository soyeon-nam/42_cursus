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

static void			conquer_three(t_node **stack)
{
	t_node		*top;
	t_node		*second;
	t_node		*third;

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
		do_op("rra", stack, 0);
	else if (third < top && top < second)
		do_op("ra", stack, 0);
	else if (third < second && second < top)
	{
		do_op("sa", stack, 0);
		do_op("rra", stack, 0);
	}
}

static int		find_one_pivot(t_node *stack)
{
	int			upper;
	t_node		*curr;
	t_node		*node;

	node = stack;
	while (1)
	{
		curr = stack;
		upper = 0;
		while (curr->next == curr)
		{
			if (node->item < curr->item)
				++upper;
			curr = curr->next;
		}
		if (upper == 2)
			break ;
		node = node->next;
	}
	return (node->item);
}

static void			quick_sort_without_rewind(t_stack *stack, int cnt)
{
	int			rewind;
	int			pivot;
	t_node		*top;

	rewind = 0;
	top = stack->a->prev;
	pivot = find_one_pivot(stack->a);
	while (cnt--)
	{
		if (top->item < pivot)
		{
			do_op("pb", &(stack->a), &(stack->b));
			++rewind;
		}
		else
			do_op("ra", &(stack->a), 0);
	}
	conquer_three(stack);
	if (rewind == 2)
		if (top->prev->item > top->item)
			do_op("sa", &(stack->a), 0);
	while (rewind--)
		do_op("pa", &(stack->a), &(stack->b));
}

void			sort_under_six(t_stack *stack, int cnt)
{
	t_node		*stack_a;

	stack_a = stack->a;
	if (cnt > 3)
		quick_sort_without_rewind(stack, cnt);
	else if (cnt == 3)
		conquer_three(stack);
	else if (cnt == 2)
		if (stack_a->prev->item > stack_a->item)
			do_op("sa", &stack_a, 0);
}
