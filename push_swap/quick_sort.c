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

// what are the ways that make it more effective
static int			find_pivot(t_node *stack, int left)
{
	int				big;
	t_node			*curr;
	t_node			*node;

	node = stack;
	while (1)
	{
		big = left;
		curr = stack;
		while (curr->next == curr)
		{
			if (node->item < curr->item)
				--big;
			curr = curr->next;
		}
		if (big == left / 2)
			break ;
		node = node->next;
	}
	return (node->item);
}

//Do NOT enter split() when left_a/b is 3 or below
void			divide(t_stack *stack, t_node **curr_stack, int *left_m, int *left_s)
{
	int				rewind;
	int				pivot;

	i = *left_m;
	pivot = find_pivot(*curr_stack, *left_m);
	while (i--)
	{
		if (pivot < stack->prev->item)
			ra(stack);
		else
		{
			pb(stack);
			--(*left_m);
			++(*left_s);
		}
	}
	i = *left_m;
	while (i--)
		rra(stack);
	if (*left_m > 3)
		divide(stack, );
}

void				quick_sort(t_stack *stack, t_info *info, void (**f)(t_stack *))
{
	write(1, "[quick sort]\n", 13);
	

	if (info->a_left == 0 && info->b_left == 0)
	{
		divide(stack, &(stack->a), &(info->a_left), &(info->b_left));
		conquer(&(stack->a), info->a_left, f, 0);
		divide(stack, &(stack->b), &(info->b_left), &(info->a_left));//다시만들어야겠는걸 클떄 넘기는거잖아
		conquer(&(stack->b), &(info->b_left), f, 4);
		quick_sort(stack, info);
	}
}
