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

// void	a_to_b(t_stack *stack, int cnt)
// {
// 	t_sort_info		info;
// 	int				rewind;			

// 	if (cnt < 7)
// 		return (conquer_a(stack, cnt));
// 	set_pivot(stack->a, &info, cnt);
// 	while (cnt--)
// 	{
// 		if (stack->a->next->item <= info.pivot1)
// 			do_op("pb", stack);
// 		else if (stack->a->next->item <= info.pivot2)
// 			do_multiple_op(stack, 2, "pb", "rb");
// 		else
// 			do_op("ra", stack);
// 	}
// 	rewind = info.large_cnt;
// 	if (info.large_cnt < info.middle_cnt)
// 		do_op("rrb", stack);
// 	while (rewind--)
// 		do_op("rrr", stack);
// 	a_to_b(stack, info.large_cnt);
// 	b_to_a(stack, info.middle_cnt);
// 	b_to_a(stack, info.small_cnt);
// }


static int	is_divided_a(t_node *stack, int cnt, int pivot)
{
	int			ret;

	ret = 0;
	while (cnt--)
		stack = stack->next;
	while (1)
	{
		if (stack->item <= pivot)
			break;
		stack = stack->prev;
		++ret;
	}
	return (ret);
}



void	a_to_b(t_stack *stack, int cnt)
{
	t_sort_info		info;
	int				rewind;			
	int				divided;

	if (cnt < 7)
	{
		if (!is_acsend(stack->a, cnt))
			return (conquer_a(stack, cnt));
		return ;	
	}
	set_pivot(stack->a, &info, cnt);
	divided = is_divided_a(stack->a, cnt, info.pivot2);
	while (cnt-- - divided)
	{
		if (stack->a->next->item <= info.pivot1)
			do_op("pb", stack);
		else if (stack->a->next->item <= info.pivot2)
			do_multiple_op(stack, 2, "pb", "rb");
		else
			do_op("ra", stack);
	}
	rewind = info.middle_cnt - info.large_cnt + divided;
	while (rewind--)
		do_op("rrb", stack);
	rewind = info.large_cnt - divided;
	while (rewind--)
		do_op("rrr", stack);
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


// void	a_to_b(t_stack *stack, int cnt)
// {
// 	t_sort_info		info;
// 	int				rewind;			
// 	int				divided;

// 	if (cnt < 7)
// 	{
// 		if (!is_acsend(stack->a, cnt))
// 			return (conquer_a(stack, cnt));
// 		return ;	
// 	}
// 	set_pivot(stack->a, &info, cnt);
// 			divided = is_divided(stack->a, cnt, info.pivot2);
// 	while (cnt-- - divided)
// 	{
// 		if ((cnt - divided) == 1 )
// 			if (stack->a->next->item > info.pivot2)
// 			{
// 				divided += 1;
// 				if (stack->a->next->next->item <= info.pivot1)
// 					do_multiple_op(stack, 2, "sa", "pb");
// 				else if (stack->a->next->next->item <= info.pivot2)
// 					do_multiple_op(stack, 3, "sa", "pb", "rb");
// 				break ;
// 			}
// 		if (stack->a->next->item <= info.pivot1)
// 			do_op("pb", stack);
// 		else if (stack->a->next->item <= info.pivot2)
// 			do_multiple_op(stack, 2, "pb", "rb");
// 		else
// 			do_op("ra", stack);
// 	}
// 	rewind = info.middle_cnt - info.large_cnt + divided;
// 	while (rewind--)
// 		do_op("rrb", stack);
// 	rewind = info.large_cnt - divided;
// 	while (rewind--)
// 		do_op("rrr", stack);
// 	b_to_a(stack, info.middle_cnt);
// 	b_to_a(stack, info.small_cnt);
// }
