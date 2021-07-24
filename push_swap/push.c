/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:35:57 by snam              #+#    #+#             */
/*   Updated: 2021/07/24 14:49:17 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pop(t_node **stack)
{
	(*stack)->prev->prev->next = *stack;
	(*stack)->prev = (*stack)->prev->prev;
}

void		top(t_node **stack, t_node **node)
{
	(*node)->next = *stack;
	(*node)->prev = (*stack)->prev;
	(*stack)->prev = *node;
	(*node)->prev->next = (*node);
}

void		push(t_node **stack1, t_node **stack2)
{

	t_node	*node;

	node = (*stack2)->prev;
	pop(stack2);
	top(stack1, &node);
}

/*pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
*/

void		pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa", 2);
}

/*pb : push b - take the first element at the top of a and put it at the top of b. Do
naothing if a is empty*/

void		pb(t_node **stack_a, t_node ** stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb", 2);
}
