/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:30:52 by snam              #+#    #+#             */
/*   Updated: 2021/07/24 21:30:37 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			divide()
{
	

}
static void			find_pivot()
{
	while (


}

//Do NOT enter split() when left_a/b is 3 or below
static void			split_a()
{
	int				rewind;
	int				pivot;

	i = info->left_a;
	pivot = find_pivot();
	while (i--)
	{
		if (pivot < stack->prev->item)
			ra();
		else
		{
			pb();
			--(info->left_a);
			++(info->left_b);
		}
	}
	i = left_a;
	while (i--)
		rra();
	if (left_a > 3)
		split_a();
}











static void			conquer_three(t_node **stack)
{
	t_node		*top;

	top = (*stack)->prev;
	if (top->item = 1)
		if (top->prev->item == 3)
			sa()
}

static void			conquer(t_node **stack, int left)
{
	if (left == 3)
		conquer_three(stack);
	if else (left == 2)
		if (*stack->prev->item > (*stack)->prev->prev->item)
			//push : how to distinguish pa and pb
	else
		return ;
}
`
void				quick_sort(t_stack *stack, t_info *info)
{
	write(1, "[quick sort]\n", 13);

	if (info->a_left == 0 && info->b_left == 0)
	{
		split_a(stack, info);
		conquer();
		split_b(stack, info);
		conquer();
		quick_sort(stack, info);
	}
}
