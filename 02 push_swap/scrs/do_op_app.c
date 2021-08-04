/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_app.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:30 by snam              #+#    #+#             */
/*   Updated: 2021/08/05 03:04:27 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pop_node(t_node **stack)
{
	if (!*stack)
		return ;
	if ((*stack)->next == *stack)
		*stack = 0;
	else
	{
		(*stack)->next->next->prev = *stack;
		(*stack)->next = (*stack)->next->next;
	}
}

void	top_node(t_node **stack, t_node **node)
{
	if (!*stack)
	{
		*stack = *node;
		(*node)->prev = *node;
		(*node)->next = *node;
	}
	else
	{
		(*node)->next = (*stack)->next;
		(*node)->prev = *stack;
		(*stack)->next = *node;
		(*node)->next->prev = (*node);
	}
}

void	rewind_stack(t_stack *stack, int rra, int rrb)
{
	int		rrr;
	int		rr;

	if (rrb >= rra)
	{
		rrr = rra;
		while (rrr--)
			do_op("rrr", stack);
		rr = rrb - rra;
		while (rr--)
			do_op("rrb", stack);
	}
	else
	{
		rrr = rrb;
		while (rrr--)
			do_op("rrr", stack);
		rr = rra - rrb;
		while (rr--)
			do_op("rra", stack);
	}
}
