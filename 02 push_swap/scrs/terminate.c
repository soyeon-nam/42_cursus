/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:01:26 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:01:26 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		free_stack(t_node *stack)
{
	t_node		*curr;
	t_node		*prev;

	curr = stack->prev;
	while (curr->prev != stack)
	{
		prev = curr->prev;
		free(curr);
		curr = NULL;
		curr = prev;
	}
	free(stack);
	free(curr);
}

void		terminate(char	***split, t_stack *stack, bool is_error)
{
	int		i;

	i = 0;
	if (split)
		while (split[i])
			free_malloc_slpit(split);
	if (stack)
	{
		if (stack->a)
			free_stack(stack->a);
		if (stack->b)
			free_stack(stack->b);
	}
	if (is_error)
		write(1, "Error\n", 6);
	exit(0);
}
