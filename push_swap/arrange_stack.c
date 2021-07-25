/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:03:00 by snam              #+#    #+#             */
/*   Updated: 2021/07/24 19:57:30 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_dup(t_node *stack, int item, int argc)
{
	t_node		*stack_curr;
	int			sign;

	stack_curr = stack;
	sign = 1;
	if (argc != 1)
		while (stack_curr)
		{
			if (stack_curr->item == item)
				return (1);
			if (stack_curr->next == stack)
				break ;
			stack_curr = stack_curr->next;
		}
	else
	{
		while (stack_curr)
		{
			if (stack_curr->item == item)
				return (1);
			if (stack_curr->next == stack)
				break ;
			if (stack_curr->item < stack_curr->next->item)
				sign = 0;
			stack_curr = stack_curr->next;
		}
		if (sign == 1 && (stack_curr->item > item))
		{
			printf("SORTED\n");
			return (2);
		}
	}
	return (0);
}

static int		add_node(t_node **stack, int item)
{
	t_node		*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (1);
	new->item = item;
	top(stack, &new);
//	if (!*stack)
//	{
//		*stack = new;
//		new->prev = new;
//		new->next = new;
//	}
//	else
//	{
//		new->next = *stack;
//		new->prev = (*stack)->prev;
//		(*stack)->prev = new;
//		new->prev->next = new;
//	}
	return (0);
}

t_node			*arrange_stack(char **argv, int argc)
{
	t_node		*stack;
	int			item;
	int			is_null;

	stack = NULL;
	while (--argc)
	{
		item = atoi_ps(argv[argc], &is_null);
		// printf("[arrange 1] %d\n", is_null);
		if (item == 0 && is_null == 1)
			error(stack);
		is_null = check_dup(stack, item, argc); // check sorted
		// printf("[arrange 2] %d\n", is_null);
		if (is_null == 1)
		{
			if (is_null == 0)
				error(stack);
			free_stack(stack);
			exit(0);		
		}
		is_null = add_node(&stack, item);
		// printf("[arrange 3] %d\n", is_null);
		if (is_null)
			error(stack);
	}
	return (stack);
}
