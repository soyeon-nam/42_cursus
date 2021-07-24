/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:53:13 by snam              #+#    #+#             */
/*   Updated: 2021/07/24 20:58:02 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(int argc, char **argv)
{
	t_info		info;
	t_stack		stack;

	stack->a = arrange_stack(argv, argc); //if fail to allocate, return
	if (!stack->a)
	{
		write(2, "Error", 5);
		exit(0);
	}
	stack->b = NULL;
	info->a_sorted = 0;
	info->b_sorted = 0;
	info->a_left = argc - 1;
	info->b_left = 0;
	quick_sort(&stack, &info);
	free_stack(stack->a);
}
