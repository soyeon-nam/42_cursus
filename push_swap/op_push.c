/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:35:57 by snam              #+#    #+#             */
/*   Updated: 2021/07/24 19:56:19 by snam             ###   ########.fr       */
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
	if (!*stack)
	{
		*stack = *node;
		*node->prev = *node;
		*node->next = *node;
	}
	else
	{
		(*node)->next = *stack;
		(*node)->prev = (*stack)->prev;
		(*stack)->prev = *node;
		(*node)->prev->next = (*node);
	}
}

static void		push(t_node **stack1, t_node **stack2)
{
	t_node	*node;

	node = (*stack2)->prev;
	pop(stack2);
	top(stack1, &node);

}

/*pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
*/

void		pa(t_stack *stack)
{
	push(&(stack->a), &(stack->b));
	write(1, "pa", 2);
}

/*pb : push b - take the first element at the top of a and put it at the top of b. Do
naothing if a is empty*/

void		pb(t_stack *stack)
{
	push(&(stack->b), &(stack->a));
	write(1, "pb", 2);
}
