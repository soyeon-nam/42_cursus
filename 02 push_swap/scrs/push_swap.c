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



						// t_node * stack_a;
						// t_node * stack_b;
						// printf("\n   [start]\n");
						// if (stack.a || stack.b)
						// {
						// 	if (stack.a)
						// 		stack_a = stack.a->next;
						// 	if (stack.b)
						// 		stack_b = stack.b->next;
						// 	while ((stack.a && stack_a != stack.a) || (stack.b && stack_b != stack.b))
						// 	{
						// 		if (stack.a && stack_a != stack.a)		
						// 		{
						// 			printf("     | %d ", stack_a->item);
						// 			stack_a = stack_a->next;
						// 		}
						// 		else
						// 			printf("     |   ");
						// 		if (stack.b && stack_b != stack.b)
						// 		{
						// 			printf("%d", stack_b->item);
						// 			stack_b = stack_b->next;
						// 		}		
						// 		printf("\n");
						// 	}
						// 	if (stack.a)
						// 		printf("     | %d ", stack.a->item);
						// 	else
						// 		printf("     |   ");
						// 	if (stack.b)
						// 		printf("%d", stack.b->item);
						// 	printf("\n");
						// 	printf("       - -\n\n");
						// }

	quick_sort(&stack);


	
							t_node * stack_a;
						t_node * stack_b;
						printf("\n   [result]\n");
						if (stack.a || stack.b)
						{
							if (stack.a)
								stack_a = stack.a->next;
							if (stack.b)
								stack_b = stack.b->next;
							while ((stack.a && stack_a != stack.a) || (stack.b && stack_b != stack.b))
							{
								if (stack.a && stack_a != stack.a)		
								{
									printf("     | %d ", stack_a->item);
									stack_a = stack_a->next;
								}
								else
									printf("     |   ");
								if (stack.b && stack_b != stack.b)
								{
									printf("%d", stack_b->item);
									stack_b = stack_b->next;
								}		
								printf("\n");
							}
							if (stack.a)
								printf("     | %d ", stack.a->item);
							else
								printf("     |   ");
							if (stack.b)
								printf("%d", stack.b->item);
							printf("\n");
							printf("       - -\n\n");
						}


	terminate(0, &stack, 0);
}
