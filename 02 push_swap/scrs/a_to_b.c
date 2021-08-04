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

static int	is_acsend(t_node *stack, int cnt)
{
	while (cnt--)
	{
		if (stack->next->item > stack->next->next->item)
			return (0);
		stack = stack->next;
	}
	return (1);
}

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
		do_op("sa", stack);
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
	int		i;

	if (cnt >= 4)
	{
		pivot = find_pivot(stack->a, cnt, cnt - 3);
		i = cnt;
		while (i--)
		{
			if (stack->a->next->item <= pivot)
				do_op("pb", stack);
			else
				do_op("ra", stack);
		}
		i = 3;
		while (i--)
			do_op("rra", stack);
		conquer_a(stack, 3);
		conquer_b(stack, cnt - 3);
	}
	else if (cnt == 3)
		conquer_a_three(stack);
	else if (cnt == 2)
		if (stack->a->next->item > stack->a->next->next->item)
			do_op("sa", stack);
}

void	a_to_b(t_stack *stack, int cnt)
{
	t_sort_info		info;

	if (is_acsend(stack->a, cnt))
		return ;
	if (cnt < 7)
		return (conquer_a(stack, cnt));
	divide_a(stack, cnt, &info);
	a_to_b(stack, info.large_cnt);
	b_to_a(stack, info.middle_cnt);
	b_to_a(stack, info.small_cnt);
}





// 						// t_node * stack_a;
// 						// t_node * stack_b;
// 						// t_node ** a = &(stack->a);
// 						// t_node ** b = &(stack->b);
// 						// printf("\n   [a_to_b]\n\n");
// 						// if (*a || *b)
// 						// {
// 						// 	if (*a)
// 						// 		stack_a = (*a)->next;
// 						// 	if (*b)
// 						// 		stack_b = (*b)->next;
// 						// 	while ((*a && stack_a != *a) || (*b && stack_b != *b))
// 						// 	{
// 						// 		if (*a && stack_a != *a)		
// 						// 		{
// 						// 			printf("     | %d ", stack_a->item);
// 						// 			stack_a = stack_a->next;
// 						// 		}
// 						// 		else
// 						// 			printf("     |   ");
// 						// 		if (*b && stack_b != *b)
// 						// 		{
// 						// 			printf("%d", stack_b->item);
// 						// 			stack_b = stack_b->next;
// 						// 		}		
// 						// 		printf("\n");
// 						// 	}
// 						// 	if (*a)
// 						// 		printf("     | %d ", (*a)->item);
// 						// 	else
// 						// 		printf("     |   ");
// 						// 	if (*b)
// 						// 		printf("%d", (*b)->item);
// 						// 	printf("\n");
// 						// 	printf("       -    -\n\n");
// 						// }
