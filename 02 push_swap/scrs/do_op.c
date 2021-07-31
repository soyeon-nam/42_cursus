/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:26 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:00:27 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static bool	op_s(t_node *head)
{
	int			tmp;

	tmp = head->item;
	head->item = head->prev->item;
	head->prev->item = tmp;
	return (1);
}

static bool	op_r(t_node **head)
{
	*head = (*head)->next;
	return (1);
}

static bool	op_rr(t_node **head)
{
	*head = (*head)->prev;
	return (1);
}

static bool	op_p(t_node **stack1, t_node **stack2)
{
	t_node		*node;

	node = *stack2;
	pop_node(stack2);
	top_node(stack1, &node);
	return (1);
}

void	do_op(char *str, t_node **a, t_node **b)
{
	if (!ft_strcmp(str, "sa") && op_s(*a))
		write(1, "sa\n", 3);
	else if (!ft_strcmp(str, "sb") && op_s(*b))
		write(1, "sb\n", 3);
	else if (!ft_strcmp(str, "ss") && op_s(*a) && op_s(*b))
		write(1, "ss\n", 3);
	else if (!ft_strcmp(str, "pa") && op_p(a, b))
		write(1, "pa\n", 3);
	else if (!ft_strcmp(str, "pb") && op_p(b, a))
		write(1, "pb\n", 3);
	else if (!ft_strcmp(str, "ra") && op_r(a))
		write(1, "ra\n", 3);
	else if (!ft_strcmp(str, "rb") && op_r(b))
		write(1, "rb\n", 3);
	else if (!ft_strcmp(str, "rr") && op_r(a) && op_r(b))
		write(1, "rr\n", 3);
	else if (!ft_strcmp(str, "rra") && op_rr(a))
		write(1, "rra\n", 4);
	else if (!ft_strcmp(str, "rrb") && op_rr(b))
		write(1, "rrb\n", 4);
	else if (!ft_strcmp(str, "rrr") && op_rr(a) && op_rr(b))
		write(1, "rrr\n", 4);
}
