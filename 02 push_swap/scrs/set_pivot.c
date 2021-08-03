/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 04:30:08 by snam              #+#    #+#             */
/*   Updated: 2021/08/01 04:30:09 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_pivot(t_node *stack, int cnt, int order)
{
	int				check;
	int				loop;
	t_node			*curr;
	t_node			*node;

	node = stack->next;
	while (1)
	{
		loop = cnt;
		check = cnt;
		curr = stack->next;
		while (loop--)
		{
			if (node->item < curr->item)
				--check;
			curr = curr->next;
		}
		if (check == order)
			break ;
		node = node->next;
	}
	return (node->item);
}

void	set_pivot(t_node *stack, t_sort_info *info, int cnt)
{
	info->large_cnt = cnt / 3;
	info->middle_cnt = (cnt - info->large_cnt) / 2;
	info->small_cnt = cnt - (info->middle_cnt + info->large_cnt);

	info->pivot1 = find_pivot(stack, cnt, info->small_cnt);
	info->pivot2 = find_pivot(stack, cnt, info->small_cnt + info->middle_cnt);
}
