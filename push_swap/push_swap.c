/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:53:13 by snam              #+#    #+#             */
/*   Updated: 2021/07/22 20:41:44 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(int argc, char **argv)
{
	t_node	*stack_a;
	
	stack_a = arrange_stack(argv, argc); //if fail to allocate, return
	if (!stack_a)
	{
		write(2, "Error", 5);
		exit(0);
	}
	quick_sort(stack_a);
	free_stack(stack_a);
}

