/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:58:27 by snam              #+#    #+#             */
/*   Updated: 2021/08/14 20:06:00 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_acsend(t_node *stack, int cnt)
{
	while (cnt--)
	{
		if (stack->next->item > stack->next->next->item)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	divide_a_56(t_stack *stack, int cnt)
{
	int		pivot;
	int		i;

	pivot = find_pivot(stack->a, cnt, cnt - 3);
	i = cnt;
	while (i--)
	{
		if (stack->a->next->item <= pivot)
			do_op("pb", stack);
		else
			do_op("ra", stack);
	}
	rewind_stack(stack, 3, 0);
	conquer_a(stack, 3);
	conquer_b(stack, cnt - 3);
}

static void	divide_a(t_stack *stack, int cnt, t_sort_info *info)
{
	int				rra;
	int				rrb;

	rra = 0;
	rrb = 0;
	set_pivot(stack->a, info, cnt);
	while (cnt--)
	{
		if (cnt == 1 && (stack->a->next->item > info->pivot2))
		{
			if (stack->a->next->next->item < info->pivot2)
			{
				do_multiple_op(stack, 2, "sa", "pb");
				break ;
			}
		}
		if ((stack->a->next->item > info->pivot2) && ++rra)
			do_op("ra", stack);
		else if ((stack->a->next->item > info->pivot1) && ++rrb)
			do_multiple_op(stack, 2, "pb", "rb");
		else
			do_op("pb", stack);
	}
	rewind_stack(stack, rra, rrb);
}

void	a_to_b(t_stack *stack, int cnt)
{
	t_sort_info		info;

	if (is_acsend(stack->a, cnt))
		return ;
	if (cnt <= 4)
		return (conquer_a(stack, cnt));
	else if (cnt <= 6)
		return (divide_a_56(stack, cnt));
	divide_a(stack, cnt, &info);
	a_to_b(stack, info.large_cnt);
	b_to_a(stack, info.middle_cnt);
	b_to_a(stack, info.small_cnt);
}
