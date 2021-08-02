/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:58:27 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 03:58:30 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	conquer_a_three(t_stack *stack)
{
	int		top;
	int		second;
	int		third;

	top = stack->a->next->item;
	second = stack->a->next->next->item;
	third = stack->a->next->next->next->item;
	if (top < third && third < second)
		do_multiple_op(stack, 3, "ra", "sa", "rra");
	else if (second < top && top < third)
		do_op("sa", &(stack->a), 0);
	else if (second < third && third < top)
		do_multiple_op(stack, 4, "sa", "ra", "sa", "rra");
	else if (third < top && top < second)
		do_multiple_op(stack, 4, "ra", "sa", "rra", "sa");
	else if (third < second && second < top)
		do_multiple_op(stack, 5, "sa", "ra", "sa", "rra", "sa");
}

void	conquer_a(t_stack *stack, int cnt)
{
	int		pivot;
	int		push;
	
	if (cnt >= 4)
	{
		pivot = find_pivot(stack->a , cnt, cnt - 3);
		push = cnt - 3;
		while (cnt--)
		{
			if (stack->a->next->item <= pivot)
				do_op("pb", &(stack->a), &(stack->b));
			else
				do_op("ra", &(stack->a), &(stack->b));
		}
		conquer_a(stack, 3);
		conquer_b(stack, push);
	}
	else if (cnt == 3)
		conquer_a_three(stack);
	else if (cnt == 2)
		if (stack->a->next->item >stack->a->next->next->item)
			do_op("sa", &(stack->a), &(stack->b));
}

void	a_to_b(t_stack *stack, int cnt)
{
	int			rewind;
	int			pivot1;
	int			pivot2;

	if (cnt < 7)
		return (conquer_a(stack, cnt));
	rewind = cnt;
	pivot1 = find_pivot(stack->a, cnt, cnt - cnt * 2 / 3);
	pivot2 = find_pivot(stack->a, cnt, cnt - cnt / 3);

	
							// printf(">>> cnt = %d\n", cnt);
							printf(">>> pivot = %d %d\n", pivot1, pivot2);


	while (cnt--)
	{
		if (stack->a->next->item <= pivot1)
			do_op("pb", &(stack->a), &(stack->b));
		else if (stack->a->next->item <= pivot2)
			do_multiple_op(stack, 2, "pb", "rb");
		else
			do_op("ra", &(stack->a), &(stack->b));
	}
	cnt = rewind;
	rewind = cnt / 3;
	while (rewind--)
		do_op("rrr", &(stack->a), &(stack->b));
	a_to_b(stack, cnt / 3);
	b_to_a(stack, cnt / 3);
	b_to_a(stack, cnt - (cnt * 2 / 3));



						// t_node * stack_a;
						// t_node * stack_b;
						// t_node **a = &(stack->a);
						// t_node **b = &(stack->b);
						// printf("\n   [do_op]\n");
						// if (*a || *b)
						// {
						// 	if (*a)
						// 		stack_a = (*a)->next;
						// 	if (*b)
						// 		stack_b = (*b)->next;
						// 	while ((*a && stack_a != *a) || (*b && stack_b != *b))
						// 	{
						// 		if (*a && stack_a != *a)		
						// 		{
						// 			printf("     | %d ", stack_a->item);
						// 			stack_a = stack_a->next;
						// 		}
						// 		else
						// 			printf("     |   ");
						// 		if (*b && stack_b != *b)
						// 		{
						// 			printf("%d", stack_b->item);
						// 			stack_b = stack_b->next;
						// 		}		
						// 		printf("\n");
						// 	}
						// 	if (*a)
						// 		printf("     | %d ", (*a)->item);
						// 	else
						// 		printf("     |   ");
						// 	if (*b)
						// 		printf("%d", (*b)->item);
						// 	printf("\n");
						// 	printf("       - -\n\n");
						// }
}
