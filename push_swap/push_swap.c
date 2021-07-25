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

static void		arrange_sorting(t_info *info, t_stack *stack, 
					void (**f)(t_stack *), int argc)
{
	stack->b = NULL;
	info->a_sorted = 0;
	info->b_sorted = 0;
	info->b_left = 0;
	info->a_left = argc - 1;
	f[0] = sa;
	f[1] = pa;
	f[2] = ra;
	f[3] = rra;
	f[4] = sb;
	f[5] = pb;
	f[6] = rb;
	f[7] = rrb;
}

void			push_swap(int argc, char **argv)
{
	t_info		info;
	t_stack		stack;
	void		(*f[8])(t_stack *);

	stack->a = arrange_stack(argv, argc); //if fail to allocate, return
	if (!stack->a)
		error();
	arrange_sorting(info, stack, f, argc);
	if (argc == 3)
		if (stack.a->prev->item > stack.a->item)
			sa(stack.a);
	else if (argc == 4)
		process_three(&(stack.a));
	else if (argc == 5)
		process_four(stack);
	else if (argc == 6)
		process_five(stack);
	else
		quick_sort(&stack, &info, f);
	free_stack(stack->a);
}
