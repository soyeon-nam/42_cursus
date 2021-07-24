/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:56:33 by snam              #+#    #+#             */
/*   Updated: 2021/07/24 21:25:26 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_node **stack)
{
	t_node		*top;
	t_node		*second;

	top = (*stack)->prev;
	second = top->prev;
	second->prev->next = top;
	(*stack)->prev = second;
	top->prev = second->prev;
	second->next = top->next;
	top->next = second;
	second->prev = top;
}
/*sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).*/

void		sa(t_node **stack)
{
	swap(stack);
	write(1, "sa", 2);
}


/*sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).*/

void		sa(t_node **stack)
{
	swap(stack);
	write(1, "sb", 2);
}


/*ss : sa and sb at the same time.*/

void		ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss", 2);
}
