/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_app.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:30 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:00:31 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pop_node(t_node **stack)
{
	if (!*stack)
		return ;
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
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
		(*node)->next = *stack;
		(*node)->prev = (*stack)->prev;
		(*stack)->prev = *node;
		(*node)->prev->next = (*node);
		*stack = *node;//check
	}
}




// ​
// void	rewind_stack(t_node **a, t_node** b, int cnt)
// {
// 	while (cnt > 0)
// 	{
// 		do_op("rrr", a, b);
// 		--cnt;
// 	}
// }
