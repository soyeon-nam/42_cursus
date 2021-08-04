/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:18 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:00:19 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	conquer_b(t_stack *stack, int cnt)
{
	int		pivot;
	int		i;

	if (cnt >= 4)
	{
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
		return ;
	}
	i = cnt;
	while (i--)
		do_op("pa", stack);
	conquer_a(stack, cnt);
}

// void	b_to_a(t_stack *stack, int cnt)
// {
// 	t_sort_info		info;
// 	int				rewind;			

// 	if (cnt < 7)
// 		return (conquer_b(stack, cnt));
// 	set_pivot(stack->b, &info, cnt);
// 	while (cnt--)
// 	{
// 		if (stack->b->next->item <= info.pivot1)
// 			do_op("rb", stack);
// 		else if (stack->b->next->item <= info.pivot2)
// 			do_multiple_op(stack, 2, "pa", "ra");
// 		else
// 			do_op("pa", stack);
// 	}
// 	a_to_b(stack, info.large_cnt);
// 	rewind = info.middle_cnt;
// 	if (info.middle_cnt < info.small_cnt)
// 		do_op("rrb", stack);
// 	while (rewind--)
// 		do_op("rrr", stack);
// 	a_to_b(stack, info.middle_cnt);
// 	b_to_a(stack, info.small_cnt);
// }



static int	is_divided_b(t_node *stack, int cnt, int pivot)
{
	int			ret;

	ret = 0;
	while (cnt--)
		stack = stack->next;
	while (1)
	{
		if (stack->item >= pivot)
			break;
		stack = stack->prev;
		++ret;
	}
	return (ret);
}


void	b_to_a(t_stack *stack, int cnt)
{
	t_sort_info		info;
	int				rewind;			
	int				divided;

	if (cnt < 7)
	{	
		if (!is_decsend(stack->b, cnt))
			return (conquer_b(stack, cnt));
		while (cnt--)
			do_op("pa", stack);
		return ;
	}
	set_pivot(stack->b, &info, cnt);
	divided = is_divided_b(stack->a, cnt, info.pivot1);
	while (cnt-- - divided)
	{
		if (stack->b->next->item <= info.pivot1)
			do_op("rb", stack);
		else if (stack->b->next->item <= info.pivot2)
			do_multiple_op(stack, 2, "pa", "ra");
		else
			do_op("pa", stack);
	}
	a_to_b(stack, info.large_cnt);

	rewind = info.small_cnt - info.middle_cnt + divided;
	if (rewind > 0)
		while (rewind--)
			do_op("rrb", stack);
	else if (rewind < 0)
		while (rewind++)
			do_op("rra", stack);
	rewind = (info.middle_cnt > info.small_cnt) ? info.small_cnt : info.middle_cnt;
	while (rewind--)
		do_op("rrr", stack);
	a_to_b(stack, info.middle_cnt);
	b_to_a(stack, info.small_cnt);
}
