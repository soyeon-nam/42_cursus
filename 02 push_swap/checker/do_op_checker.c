/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:26 by snam              #+#    #+#             */
/*   Updated: 2021/08/05 03:04:17 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static bool	op_s(t_node *head)
{
	int			tmp;

	if (!head)
		return (0);
	tmp = head->next->item;
	head->next->item = head->next->next->item;
	head->next->next->item = tmp;
	return (1);
}

bool	op_r(t_node **head)
{
	if (!*head)
		return (0);
	*head = (*head)->next;
	return (1);
}

static bool	op_rr(t_node **head)
{
	if (!*head)
		return (0);
	*head = (*head)->prev;
	return (1);
}

static bool	op_p(t_node **stack1, t_node **stack2)
{
	t_node		*node;

	if (!*stack2)
		return (0);
	if (*stack2)
	{
		node = (*stack2)->next;
		pop_node(stack2);
		top_node(stack1, &node);
	}
	return (1);
}

void	do_op(char *str, t_stack *stack)
{
	if (!ft_strcmp(str, "sa"))
		op_s(stack->a);
	else if (!ft_strcmp(str, "sb"))
		op_s(stack->b);
	else if (!ft_strcmp(str, "ss") && op_s(stack->a))
		op_s(stack->b);
	else if (!ft_strcmp(str, "pa"))
		op_p(&(stack->a), &(stack->b));
	else if (!ft_strcmp(str, "pb"))
		op_p(&(stack->b), &(stack->a));
	else if (!ft_strcmp(str, "ra"))
		op_r(&(stack->a));
	else if (!ft_strcmp(str, "rb"))
		op_r(&(stack->b));
	else if (!ft_strcmp(str, "rr") && op_r(&(stack->a)))
		op_r(&(stack->b));
	else if (!ft_strcmp(str, "rra"))
		op_rr(&(stack->a));
	else if (!ft_strcmp(str, "rrb"))
		op_rr(&(stack->b));
	else if (!ft_strcmp(str, "rrr") && op_rr(&(stack->a)))
		op_rr(&(stack->b));
	else
		terminate(0, stack, 1);
}
