/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:21:46 by snam              #+#    #+#             */
/*   Updated: 2021/07/23 21:22:06 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
*/
void		reverse(t_node **stack)
{
	*stack = (*stack)->next;
}

void		rra(t_node **stack)
{
	reverse(stack);
	write(1, "rra", 3);
}
/*rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.*/

void		rrb(t_node **stack)
{
	reverse(stack);
	write(1, "rrb", 3);
}


/*rrr : rra and rrb at the same time.*/


void		rrr(t_node **stack_a, t_node *stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	write(1, "rrr", 3);
}
