/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:01:16 by snam              #+#    #+#             */
/*   Updated: 2021/08/14 20:07:05 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	count_item(t_node *stack)
{
	int			ret;
	t_node		*curr_stack;

	if (!stack)
		return (0);
	ret = 1;
	curr_stack = stack->next;
	while (curr_stack != stack)
	{
		curr_stack = curr_stack->next;
		++ret;
	}
	return (ret);
}

void	quick_sort(t_stack *stack)
{
	int			cnt;

	cnt = count_item(stack->a);
	if (cnt >= 6)
		a_to_b(stack, cnt);
	else if (cnt >= 2)
		sort_under_six(stack, cnt);
	else if (cnt == 0)
		terminate(0, stack, 1);
	terminate(0, stack, 0);
}
