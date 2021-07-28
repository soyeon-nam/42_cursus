/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:01:16 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:01:17 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int				count_item(t_node *stack)
{
	int			ret;
	t_node		*curr_stack;

	ret = 1;
	curr_stack = stack;
	while (curr_stack != stack)
	{
		curr_stack = curr_stack->next;
		++ret;
	}
	return (ret);
}

void			quick_sort(t_stack *stack)
{
	int			cnt;

	cnt = count_item(stack->a);
	if (cnt >= 6)
		a_to_b();
	else if (2 <= cnt && cnt <= 5)
		sort_under_six(stack, cnt);
}
