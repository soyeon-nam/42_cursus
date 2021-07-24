/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:34:20 by snam              #+#    #+#             */
/*   Updated: 2021/07/24 15:25:39 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
