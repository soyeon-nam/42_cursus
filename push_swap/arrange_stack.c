/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:03:00 by snam              #+#    #+#             */
/*   Updated: 2021/07/22 20:39:30 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool		check_dup(t_node *stack, int item)
{
	t_node		*stack_curr;

	stack_curr = stack;
	while (stack_curr)
	{
		if (stack_curr->item == item)
			return (1);
		if (stack_curr->next == stack)
			break ;
		stack_curr = stack_curr->next;
	}
	return (0);
}

t_node			*arrange_stack(int argc, char **argv)
{
	t_node		*stack;
	int			item;
	bool		is_null;

	while (--argc)
	{
		item = atoi(argv[argc]);
		if (item == NULL && is_null == 0)
		{
			free_stack(stack);
			return (NULL);
		}
		is_null = check_dup(stack, item);
		if (is_null)
		{
			free_stack(stack);
			return (NULL);
		}
		is_null = add_node(&stack, item);
		if (is_null)
		{
			free_stack(stack);
			return (NULL);
		}
	}
	return (stack);
}
