/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:18 by snam              #+#    #+#             */
/*   Updated: 2021/08/05 03:03:56 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_decsend(t_node *stack, int cnt)
{
	while (cnt--)
	{
		if (stack->next->item > stack->next->next->item)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	divide_b_56(t_stack *stack, int cnt)
{
	int		pivot;
	int		i;

	pivot = find_pivot(stack->b, cnt, cnt - 3);
	i = cnt;
	while (i--)
	{
		if (stack->b->next->item > pivot)
			do_op("pa", stack);
		else
			do_op("rb", stack);
	}
	conquer_a(stack, 3);
	i = cnt - 3;
	while (i--)
		do_op("rrb", stack);
	conquer_b(stack, cnt - 3);
}

static int	divide_b(t_stack *stack, int cnt, t_sort_info *info)
{
	set_pivot(stack->b, info, cnt);
	while (cnt--)
	{
		if (cnt == 1 && (stack->a->next->item <= info->pivot1))
		{
			do_multiple_op(stack, 2, "sb", "pa");
			return (1);
		}
		if ((stack->b->next->item <= info->pivot1))
			do_op("rb", stack);
		else if ((stack->b->next->item <= info->pivot2))
			do_multiple_op(stack, 2, "pa", "ra");
		else
			do_op("pa", stack);
	}
	return (0);
}

void	b_to_a(t_stack *stack, int cnt)
{
	t_sort_info		info;
	int				rewind_completed;

	if (is_decsend(stack->b, cnt))
	{	
		while (cnt--)
			do_op("pa", stack);
		return ;
	}
	if (cnt <= 4)
		return (conquer_b(stack, cnt));
	else if (cnt <= 6)
		return (divide_b_56(stack, cnt));
	rewind_completed = divide_b(stack, cnt, &info);
	a_to_b(stack, info.large_cnt);
	rewind_stack(stack, info.middle_cnt - rewind_completed, \
				info.small_cnt - rewind_completed);
	a_to_b(stack, info.middle_cnt);
	b_to_a(stack, info.small_cnt);
}
