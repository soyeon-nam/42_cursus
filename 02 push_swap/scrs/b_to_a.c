/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:00:18 by snam              #+#    #+#             */
/*   Updated: 2021/07/29 04:00:19 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	conquer_b_three(t_stack *stack)
{
	int		top;
	int		second;
	int		third;

	top = stack->b->next->item;
	second = stack->b->next->next->item;
	third = stack->b->next->next->next->item;
	if (top < second && second < third)
		do_multiple_op(stack, 5, "sb", "rb", "sb", "rrb", "sb");
	else if (top < third && third < second)
		do_multiple_op(stack, 4, "sb", "rb", "sb", "rrb");
	else if (second < top && top < third)
		do_multiple_op(stack, 4, "rb", "sb", "rrb", "sb");
	else if (second < third && third < top)
		do_multiple_op(stack, 3, "rb", "sb", "rrb");
	else if (third < top && top < second)
		do_op("sb", &(stack->a), &(stack->b));
}

void	conquer_b(t_stack *stack, int cnt)
{
	int		pivot;
	int		i;
	int		j;

	j = 0;
	if (cnt >= 4)
	{
		pivot = find_pivot(stack->b , cnt, cnt - 3);
		i = cnt;
		while (i--)
		{
			if (stack->b->next->item > pivot)
			{
				do_op("pa", &(stack->a), &(stack->b));
				++j;
			}
			else
				do_op("rb", &(stack->a), &(stack->b));
		}
		conquer_a(stack, 3);

						while (j--)
							do_op("rrb", &(stack->a), &(stack->b));

		conquer_b(stack, cnt - 3);
		cnt -= 3;
	}
	else if (cnt == 3)
		conquer_b_three(stack);
	else if (cnt == 2)
		if (stack->b->next->item < stack->b->next->next->item)
			do_op("sb", &(stack->a), &(stack->b));
	while (cnt--)
		do_op("pa", &(stack->a), &(stack->b));
}

void	b_to_a(t_stack *stack, int cnt)
{
	int			rewind;
	int			pivot1;
	int			pivot2;

	if (cnt < 7)
		return (conquer_b(stack, cnt));
	rewind = cnt;
	pivot1 = find_pivot(stack->b, cnt, cnt / 3);
	pivot2 = find_pivot(stack->b, cnt, cnt * 2 / 3);


							// printf(">>> pivot = %d %d\n", pivot1, pivot2);


	while (cnt--)
	{
		if (stack->b->next->item < pivot1)
			do_op("ra", &(stack->a), &(stack->b));
		else if (stack->b->next->item < pivot2)
			do_multiple_op(stack, 2, "pa", "ra");
		else
			do_op("pa", &(stack->a), &(stack->b));
	}
	a_to_b(stack, cnt / 3);
	cnt = rewind;
	rewind = cnt - (cnt * 2 / 3);
	while (rewind--)
		do_op("rrr", &(stack->a), &(stack->b));
	a_to_b(stack, cnt / 3);
	b_to_a(stack, cnt - (cnt * 2 / 3));


						// 	t_node * stack_a;
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
