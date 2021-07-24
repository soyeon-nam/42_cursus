/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:34:20 by snam              #+#    #+#             */
/*   Updated: 2021/07/23 18:44:20 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_stack(t_node *stack)
{
	t_node		*curr;
	t_node		*prev;

	printf("FREE");
	curr = stack->prev;
	while (curr->prev != stack)
	{
		printf("in");
		prev = curr->prev;
		free(curr);
		curr = NULL;
		curr = prev;
	}
	printf("out");
	free(stack);
	free(curr);


	// curr = stack;
	// while (curr->next != stack)
	// {
	// 	next = curr->next;
	// 	free(curr);
	// 	curr = NULL;
	// 	curr = next;
	// }
	// free(curr);
}
