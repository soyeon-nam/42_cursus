/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:01:05 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:01:08 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			push_swap(char ***arr)
{
	t_stack		stack;
	int			i;

	parse(arr, &stack);
	i = -1;
	while (arr[++i])
		free_malloc_slpit(arr[i]);

						// if (stack.a)
						// {
						// 	t_node * stack_a;
						// 	stack_a = stack.a->next;
						// 	printf("--start--\n");
						// 	while (stack_a != stack.a)
						// 	{
						// 		printf("%d\n", stack_a->item);
						// 		stack_a = stack_a->next;
						// 	}
						// 	printf("%d\n", stack.a->item);
						// }
						// printf("----\n");
						// if (stack.b)
						// {
						// 	t_node * stack_b;
						// 	stack_b = stack.b->next;
						// 	while (stack_b != stack.b)
						// 	{
						// 	printf("%d\n", stack_b->item);
						// 	stack_b = stack_b->next;
						// 	}
						// 	printf("%d\n", stack.b->item);
						// }
						// printf("----\n\n");

	quick_sort(&stack);
	terminate(0, &stack, 0);
}
