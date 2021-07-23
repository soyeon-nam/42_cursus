/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:34:20 by snam              #+#    #+#             */
/*   Updated: 2021/07/22 23:37:17 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_stack(t_node *stack)
{
	t_node		*curr;

	while (stack)
	{
		curr = stack->next;
		free(stack);
		stack = curr;
	}
}