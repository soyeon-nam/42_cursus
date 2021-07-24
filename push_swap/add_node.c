/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caculate_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:23:20 by snam              #+#    #+#             */
/*   Updated: 2021/07/23 18:07:00 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		add_node(t_node **stack, int item)
{
	t_node		*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		printf("malloc failed in add node");
		return (1);
	}
	new->item = item;
	if (!*stack)
	{printf("start\n");
		*stack = new;
		new->prev = new;
		new->next = new;
	}
	else
	{
		printf("ing\n");
		new->next = *stack;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		new->prev->next = new;
	}
	return (0);
}
